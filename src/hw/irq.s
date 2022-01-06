@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@
.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.global         IRQ_TABLE
bss IRQ_TABLE
    .align      2
    .fill       14, 8, 0
    .word       0
endb

bss CRITICAL_SECTION
    .byte 0     @ Nest Counter
    .byte 0     @ Saved IME value
endb

.set REG_IE,      0x04000200
.set REG_IF,      0x04000202
.set REG_IME,     0x04000208
.set IRQ_HANDLER, 0x03007FFC

@ bool irqMasterEnable(void);
@
@ r0 = REG_IME
@ r1 = &REG_IME
@ r2 = #1
fn irqMasterEnable thumb
    movs        r2, #1
    ldr         r1, =REG_IME
    ldrh        r0, [r1]
    strh        r2, [r1]
    bx          lr
endfn

@ bool irqMasterDisable(void);
@
@ r0 = REG_IME
@ r1 = &REG_IME
@
@ We can disable IME by writing its own address to it, since bit 0 is 0.
fn irqMasterDisable thumb
    ldr         r1, =REG_IME
    ldrh        r0, [r1]
    strh        r1, [r1]
    bx          lr
endfn

@ bool irqMasterSetEnabled(bool enable);
@
@ r0 = REG_IME
@ r1 = &REG_IME
@ r2 = enable
fn irqMasterSetEnabled thumb
    movs        r2, r0
    ldr         r1, =REG_IME
    ldrh        r0, [r1]
    strh        r2, [r1]
    bx          lr
endfn

@ u16 irqEnable(u16 irqs);
@
@ r0 = REG_IE (previous)
@ r1 = &REG_IE
@ r2 = REG_IME
@ r3 = REG_IE (new)
fn irqEnable thumb
    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #8]
    strh        r1, [r1, #8]
    @ REG_IE |= irqs;
    movs        r3, r0
    ldrh        r0, [r1]
    orrs        r3, r3, r0
    strh        r3, [r1]
    @ REG_IME = old_ime;
    strh        r2, [r1, #8]
    bx          lr
endfn

@ u16 irqDisable(u16 irqs);
@
@ r0 = REG_IE (previous)
@ r1 = &REG_IE
@ r2 = REG_IME
@ r3 = REG_IE (new)
fn irqDisable thumb
    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #8]
    strh        r1, [r1, #8]
    @ REG_IE &= ~irqs;
    mvns        r3, r0
    ldrh        r0, [r1]
    ands        r3, r3, r0
    strh        r3, [r1]
    @ REG_IME = old_ime
    strh        r2, [r1, #8]
    bx          lr
endfn

@ u16 irqSetEnabled(u16 irqs);
@
@ r0 = REG_IE (new)
@ r1 = &REG_IE
@ r2 = REG_IME
@ r3 = REG_IE (old)
fn irqSetEnabled thumb
    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #8]
    strh        r1, [r1, #8]
    @ REG_IE = irqs;
    movs        r3, r0
    ldrh        r0, [r1]
    strh        r3, [r1]
    @ REG_IME = old_ime;
    strh        r2, [r1, #8]
    bx          lr
endfn

.macro reg_ie_offset val
    .hword (0x04000000 + \val) - REG_IE
.endm

rdata IRQ_SOURCES
    .hword 0x0008; reg_ie_offset 0x0004 @ LCD V-Blank, DISPSTAT
    .hword 0x0010; reg_ie_offset 0x0004 @ LCD H-Blank, DISPSTAT
    .hword 0x0020; reg_ie_offset 0x0004 @ LCD V-Count, DISPSTAT
    .hword 0x0040; reg_ie_offset 0x0102 @ Timer 0,     TM0CNT
    .hword 0x0040; reg_ie_offset 0x0106 @ Timer 1,     TM1CNT
    .hword 0x0040; reg_ie_offset 0x010A @ Timer 2,     TM2CNT
    .hword 0x0040; reg_ie_offset 0x010E @ Timer 3,     TM3CNT
    .hword 0x4000; reg_ie_offset 0x0128 @ Serial IO,   SIOCNT
    .hword 0x4000; reg_ie_offset 0x00BA @ DMA 0,       DMA0CNT
    .hword 0x4000; reg_ie_offset 0x00C6 @ DMA 1,       DMA1CNT
    .hword 0x4000; reg_ie_offset 0x00D2 @ DMA 2,       DMA2CNT
    .hword 0x4000; reg_ie_offset 0x00DE @ DMA 3,       DMA3CNT
    .hword 0x4000; reg_ie_offset 0x0132 @ Keypad,      KEYCNT
    .hword 0x0000; reg_ie_offset 0x0000 @ Cartridge,   -
endr

@ u16 irqEnableFull(u16 irqs);
@
@ r0 = REG_IE (previous)
@ r1 = &REG_IE
@ r2 = REG_IME
@ r3 = REG_IE (new)
@
@ In loop:
@
@ r0 = irqs
@ r1 = REG_IE
@ r2 = Register flag
@ r3 = IRQ_SOURCES
@ r4 = Register offset from IE
@ r5 = Register value
fn irqEnableFull thumb
    @ irqs &= IRQ_MASK;
    lsls        r0, r0, #19
    lsrs        r0, r0, #19

    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #8]
    strh        r1, [r1, #8]

    push        {r0, r2, r4, r5}

    ldr         r3, =IRQ_SOURCES

.Lief_loop:
    lsrs        r0, r0, #1
    bcc         .Lief_continue

    @ load from table
    ldr         r2, [r3]
    @ sign extend offset into r4
    asrs        r4, r2, #16

    ldrh        r5, [r1, r4]
    orrs        r5, r5, r2
    strh        r5, [r1, r4]

.Lief_continue:
    adds        r3, r3, #4
    cmp         r0, #0
    bne         .Lief_loop

.Lief_break:
    pop         {r0, r2, r4, r5}

    movs        r3, r0
    ldrh        r0, [r1]
    orrs        r3, r3, r0
    strh        r3, [r1]

    strh        r2, [r1, #8]
    bx          lr
endfn

@ u16 irqDisableFull(u16 irqs);
@
@ r0 = REG_IE (previous)
@ r1 = &REG_IE
@ r2 = REG_IME
@ r3 = REG_IE (new)
@
@ In loop:
@
@ r0 = irqs
@ r1 = &REG_IE
@ r2 = Register flag
@ r3 = IRQ_SOURCES
@ r4 = Register offset
@ r5 = Register value
fn irqDisableFull thumb
    @ irqs &= IRQ_MASK;
    lsls        r0, r0, #19
    lsrs        r0, r0, #19

    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #8]
    strh        r1, [r1, #8]

    push        {r0, r2, r4, r5}

    ldr         r3, =IRQ_SOURCES
.Lidf_loop:
    lsrs        r0, r0, #1
    bcc         .Lidf_continue

    ldr         r2, [r3]
    asrs        r4, r2, #16

    ldrh        r5, [r1, r4]
    bics        r5, r5, r2
    strh        r5, [r1, r4]

.Lidf_continue:
    adds        r3, r3, #4
    cmp         r0, #0
    bne         .Lidf_loop

.Lidf_break:
    pop         {r0, r2, r4, r5}

    mvns        r3, r0
    ldrh        r0, [r1]
    ands        r3, r3, r0
    strh        r3, [r1]

    strh        r2, [r1, #8]
    bx          lr
endfn

fn irqCriticalSectionEnter thumb
    @ r1 = REG_IME
    @ REG_IME = 0
    ldr         r0, =REG_IME
    ldrh        r1, [r0]
    strh        r0, [r0]

    @ if (CRITICAL_SECTION) b .Lecs_inc
    ldr         r2, =CRITICAL_SECTION
    ldrb        r3, [r2]
    cmp         r3, #0
    bne         .Lecs_inc

    @ Save IME
    strb        r1, [r2, #1]

.Lecs_inc:
    adds        r3, r3, #1
    strb        r3, [r2]
    bx          lr
endfn

fn irqCriticalSectionExit thumb
    @ r1 = REG_IME
    @ REG_IME = 0
    ldr         r0, =REG_IME
    ldrh        r1, [r0]
    strh        r0, [r0]

    ldr         r2, =CRITICAL_SECTION
    ldrb        r3, [r2]
    cmp         r3, #1
    @ >= 1: just decrement
    bgt         .Lxcs_dec
    @ == 0: do nothing
    blt         .Lxcs_ret
    @ == 1: restore saved IME
    ldrb        r1, [r2, #1]
.Lxcs_dec:
    subs        r3, r3, #1
    strb        r3, [r2]
.Lxcs_ret:
    strh        r1, [r0]
    bx          lr
endfn

fn irqCriticalSectionActive thumb
    ldr         r0, =CRITICAL_SECTION
    ldr         r0, [r0]
    subs        r1, r0, #1
    sbcs        r0, r0, r1
.Lcsa_out:
    bx          lr
endfn

@ extern void irqInit(IRQHandler *isr);
fn irqInitDefault thumb
    ldr         r0, =irqDefaultHandler
sfn irqInit
    movs        r1, #0
    mvns        r2, r1
    ldr         r3, =REG_IE

    @ REG_IME = 0
    strh        r1, [r3, #8]
    @ REG_IE = 0
    strh        r1, [r3]
    @ REG_IF = 0xFFFF
    strh        r2, [r3, #2]

    @ IRQ_HANDLER = r0
    ldr         r1, =0x03007FFC
    str         r0, [r1]

    @ REG_IME = 1
    strh        r2, [r3, #8]
    bx          lr
endsfn
endfn

@ r0    REG_BASE
@ r1    IE & IF
@ r2    <tmp>
@ r3    <tmp>
@ r12   IME
fn irqDefaultHandler arm
    @ Theoretically this is redundant because
    @ the BIOS IRQ vector already puts 0x04000000 in r0...
    @ But I doubt (m)any emulators HLE-ing the BIOS would get this right, lol
    mov         r1, #0x04000000

    @ Disable IME (r12)
    ldr         r12, [r1, #0x208]
    str         r1, [r1, #0x208]

    @ Get IE & IF (r0, can be read by subsequent handler)
    ldr         r0, [r1, #0x200]!
    and         r0, r0, r0, lsr #16

    @ Ack IF
    strh        r0, [r1, #2]

    @ Ack IFBIOS (r2)
    ldr         r2, [r1, #-0x208]
    orr         r2, r2, r0
    str         r2, [r1, #-0x208]

    @ Search IRQ_TABLE for a handler matching our flags.
    @ We have at most 14 unique entries, meaning we can use the 15th entry
    @ as a sentinel, saving the need for a loop counter.
    @ Allowing us, in turn, to sneak REG_BASE past in r1
    ldr         r2, =IRQ_TABLE

.Lsearch:
    ldr         r3, [r2], #8
    tst         r0, r3
    bne         .Ldispatch
    tst         r3, r3
    bne         .Lsearch
    b           .Lexit

.Ldispatch:
    mrs         r3, spsr
    msr         cpsr_c, #0x5F
    push        {r1, r3, r12, lr}

    ldr         r2, [r2, #-4]
    mov         lr, pc
    bx          r2

    pop         {r1, r3, r12, lr}
    msr         cpsr_c, #0xD2
    msr         spsr, r3

.Lexit:
    strh        r12, [r1, #8]
    bx          lr
endfn

@ vim:ft=armv4 et sta sw=4 sts=8
