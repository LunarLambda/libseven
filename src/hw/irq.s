@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@
.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/irq.s"

CONST OFF_IE_IF,  REG_IF  - REG_IE
CONST OFF_IE_IME, REG_IME - REG_IE
CONST OFF_IE_IFBIOS, REG_IFBIOS - REG_IE

bss IRQ_TABLE
    .fill       15, 8, 0
    _IRQ_TABLE_IRQSET:
    .word       0
endb

bss IRQ_CRITICAL_SECTION
    .byte       0
    .byte       0
endb

CONST IRQ_TABLE_IRQSET, _IRQ_TABLE_IRQSET - IRQ_TABLE

.macro reg_ie_offset val
    .hword \val - OFF_IE
.endm

rodata IRQ_SOURCES .align=2
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

@ void irqInit(IRQHandler *isr);
@
fn irqInit thumb
    movs        r1, #0
    mvns        r2, r1
    ldr         r3, =REG_IE

    @ REG_IME = 0
    strh        r1, [r3, #OFF_IE_IME]
    @ REG_IE = 0
    strh        r1, [r3]
    @ REG_IF = 0xFFFF
    strh        r2, [r3, #OFF_IE_IF]

    @ IRQ_HANDLER = r0
    ldr         r1, =IRQ_HANDLER
    str         r0, [r1]

    @ REG_IME = 1
    strh        r2, [r3, #OFF_IE_IME]
    bx          lr
endfn

@ void irqInitDefault(void)
@
fn irqInitDefault thumb
    ldr         r0, =irqDefaultHandler
    b           irqInit
endfn

@ void irqInitSimple(IrqCallbackFn *f)
@
fn irqInitSimple thumb
    ldr         r1, =IRQ_CALLBACK_FN
    str         r0, [r1]
    ldr         r0, =irqSimpleHandler
    b           irqInit
endfn

@ void irqInitStub(void)
@
fn irqInitStub thumb
    ldr         r0, =irqStubHandler
    b           irqInit
endfn

@ typedef void IrqCallbackFn(u16 irqs);
@
@ bool irqCallbackSet(u16 irqs, IrqCallbackFn *fn, u16 priority)
@
@ r0    irqs
@ r1    fn
@ r2    priority
@ r3    IRQ_TABLE
@ r4    &REG_IME
@ r5    REG_IME
@ r6    prio+irqs from table
@ r7    prio/fn from table
fn irqCallbackSet thumb
    push        {r4, r5, r6, r7}

    @ Drop unused IRQ bits
    lsls        r0, r0, #18
    lsrs        r0, r0, #18
    beq         .Lica_fail

    @ Disable IME
    ldr         r4, =REG_IME
    ldr         r5, [r4]
    str         r4, [r4]

    @ Check if IRQs already have entries
    ldr         r3, =IRQ_TABLE
    ldr         r6, [r3, #IRQ_TABLE_IRQSET]
    tst         r0, r6
    bne         .Lica_fail

    @ Add IRQs to bitset
    orrs        r6, r6, r0
    str         r6, [r3, #IRQ_TABLE_IRQSET]

    @ Merge irqs+prio
    lsls        r6, r2, #16
    orrs        r0, r0, r2

1:
    @ Load irqs+prio of current slot
    ldr         r6, [r3]
    @ if (prio+irq == 0): empty slot
    cmp         r6, #0
    beq         .Lica_append
    @ Get prio
    lsrs        r7, r6, #16
    @ if (slot_prio  > prio): insert here
    cmp         r7, r2
    bgt         .Lica_insert
    @ if (slot_prio == prio): try merging
    beq         .Lica_try_merge

2:
    @ Next attempt
    adds        r3, r3, #8
    b           1b

.Lica_fail:
    movs        r0, #0
    b           .Lica_exit

.Lica_try_merge:
    @ If functions match, just OR in the IRQs
    ldr         r7, [r3, #4]
    cmp         r7, r1
    bne         2b
    @ Get irqs
    lsls        r0, r0, #16
    lsrs        r0, r0, #16
    orrs        r6, r6, r0
    str         r6, [r3]
    b           .Lica_success

.Lica_insert:
    movs        r2, r3

    @ Find end of table
1:
    adds        r2, r2, #8
    ldr         r6, [r2]
    cmp         r6, #0
    bne         1b

    @ Shift slots forwards
1:
    @ Load slot
    ldm         r2!, {r6, r7}
    @ Move it back
    stm         r2!, {r6, r7}
    @ Go back one slot, accounting for ldm/stm writeback
    subs        r2, r2, #24
    @ We're done when r2 reaches the slot we want to write
    cmp         r2, r3
    bne         1b

.Lica_append:
    @ Write slot
    stm         r3!, {r0, r1}
.Lica_success:
    movs        r0, #1

.Lica_exit:
    @ Restore IME
    str         r5, [r4]
    pop         {r4, r5, r6, r7}
    bx          lr
endfn

@ bool irqCallbackDelete(u16 irqs);
@
@ r0    irqs
@ r1    &REG_IME
@ r2    REG_IME
@ r3    IRQ_TABLE
@ r4    IRQ_TABLE_IRQSET
@ r5    slot
@ r6    temp
@ r7    temp
@
@ TODO: Allow deleting multiple callbacks
fn irqCallbackDelete thumb
    push        {r4, r5, r6, r7}

    @ Drop unused IRQ bits
    lsls        r0, r0, #18
    lsrs        r0, r0, #18
    beq         .Licd_fail

    @ Disable IME
    ldr         r1, =REG_IME
    ldr         r2, [r1]
    str         r1, [r1]

    @ Check if IRQs already have entries
    ldr         r3, =IRQ_TABLE
    ldr         r4, [r3, #IRQ_TABLE_IRQSET]

    @ To test if irqs is a subset of irq_set
    @ We can do (irqs & ~irq_set) == 0
    @ If this is not true, we can't hope to remove the IRQs from the table.
    movs        r5, r0
    bics        r5, r5, r4
    bne         .Licd_fail

    movs        r5, r3
    @ Find slot
    @ We need to figure out if the irqs to remove are a subset of any slot
1:
    ldr         r6, [r5]
    cmp         r6, #0
    beq         .Licd_fail
    @ subset check
    movs        r7, r0
    bics        r7, r7, r6
    beq         .Licd_remove
    adds        r5, r5, #8
    b           1b

.Licd_fail:
    movs        r0, #0
    b           .Licd_exit

.Licd_remove:
    @ we found a slot, the address is in r5
    @ update irqset
    bics        r4, r4, r0
    str         r4, [r3, #IRQ_TABLE_IRQSET]
    @ Clear bits
    bics        r6, r6, r0
    str         r6, [r5]
    @ Is the slot now empty?
    bne         .Licd_success

.Licd_shift:
    @ r1 holds &REG_IME
    @ r2 holds REG_IME
    @ r5 holds slot address
1:
    @ read next slot
    adds        r5, r5, #8
    ldm         r5!, {r3, r4}
    @ return to current slot
    subs        r5, r5, #16
    @ write slot
    stm         r5!, {r3, r4}
    @ if we copied a zero slot, we're done
    cmp         r3, #0
    bne         1b

.Licd_success:
    movs        r0, #1

.Licd_exit:
    str         r2, [r1]
    pop         {r4, r5, r6, r7}
    bx          lr
endfn

@ IrqCallbackFn* irqCallbackLookup(u16 irqs)
@
@ r0    irqs
@ r1    IRQ_TABLE
fn irqCallbackLookup arm
    ldr         r1, =IRQ_TABLE
    ldr         r2, [r1, #IRQ_TABLE_IRQSET]
    tst         r2, r0
    moveq       r0, #0
    bxeq        lr

1:
    ldr         r2, [r1], #8
    tst         r2, r0
    beq         1b

    ldr         r0, [r1, #-4]
    bx          lr
endfn

@ u16 irqEnable(u16 irqs)
@
@ r0    REG_IE (previous)
@ r1    &REG_IE
@ r2    REG_IME
@ r3    irqs, REG_IE (new)
fn irqEnable thumb
    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #OFF_IE_IME]
    strh        r1, [r1, #OFF_IE_IME]
    @ REG_IE |= irqs;
    movs        r3, r0
    ldrh        r0, [r1]
    orrs        r3, r3, r0
    strh        r3, [r1]
    @ REG_IME = old_ime;
    strh        r2, [r1, #OFF_IE_IME]
    bx          lr
endfn

@ u16 irqDisable(u16 irqs)
@
@ r0    REG_IE (previous)
@ r1    &REG_IE
@ r2    REG_IME
@ r3    irqs, REG_IE (new)
fn irqDisable thumb
    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #OFF_IE_IME]
    strh        r1, [r1, #OFF_IE_IME]
    @ REG_IE &= ~irqs;
    mvns        r3, r0
    ldrh        r0, [r1]
    ands        r3, r3, r0
    strh        r3, [r1]
    @ REG_IME = old_ime
    strh        r2, [r1, #OFF_IE_IME]
    bx          lr
endfn

@ u16 irqEnableFull(u16 irqs)
@
@ r0    REG_IE (previous)
@ r1    &REG_IE
@ r2    REG_IME
@ r3    REG_IE (new)
@
@ In loop:
@
@ r0    irqs
@ r1    REG_IE
@ r2    Register flag
@ r3    IRQ_SOURCES
@ r4    Register offset from IE
@ r5    Register value
fn irqEnableFull thumb
    @ irqs &= IRQ_MASK;
    lsls        r0, r0, #19
    lsrs        r0, r0, #19

    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #OFF_IE_IME]
    strh        r1, [r1, #OFF_IE_IME]

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

    strh        r2, [r1, #OFF_IE_IME]
    bx          lr
endfn

@ u16 irqDisableFull(u16 irqs)
@
@ r0    REG_IE (previous)
@ r1    &REG_IE
@ r2    REG_IME
@ r3    REG_IE (new)
@
@ In loop:
@
@ r0    irqs
@ r1    &REG_IE
@ r2    Register flag
@ r3    IRQ_SOURCES
@ r4    Register offset
@ r5    Register value
fn irqDisableFull thumb
    @ irqs &= IRQ_MASK;
    lsls        r0, r0, #19
    lsrs        r0, r0, #19

    @ REG_IME = 0;
    ldr         r1, =REG_IE
    ldrh        r2, [r1, #OFF_IE_IME]
    strh        r1, [r1, #OFF_IE_IME]

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

    strh        r2, [r1, #OFF_IE_IME]
    bx          lr
endfn

@ void irqCriticalSectionEnter(void)
@
fn irqCriticalSectionEnter thumb
    ldr         r0, =REG_IME
    ldrh        r1, [r0]
    strh        r0, [r0]

    ldr         r2, =IRQ_CRITICAL_SECTION
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

@ void irqCriticalSectionExit(void)
@
fn irqCriticalSectionExit thumb
    ldr         r0, =REG_IME
    ldrh        r1, [r0]
    strh        r0, [r0]

    ldr         r2, =IRQ_CRITICAL_SECTION
    ldrb        r3, [r2]
    subs        r3, r3, #1
    blo         .Lxcs_ret
    @ Store
    strb        r3, [r2]
    bne         .Lxcs_ret
    @ Restore IME
    ldrb        r1, [r2, #1]
    strh        r1, [r0]
.Lxcs_ret:
    bx          lr
endfn

@ bool irqCriticalSectionActive(void)
@
fn irqCriticalSectionActive thumb
    ldr         r0, =IRQ_CRITICAL_SECTION
    ldrb        r0, [r0]
    subs        r1, r0, #1
    sbcs        r0, r0, r1
.Lcsa_out:
    bx          lr
endfn

@ void irqDefaultHandler(void)
@
@ r0    REG_BASE
@ r1    IE & IF
@ r2    <tmp>
@ r3    <tmp>
@ r12   IME
fn irqDefaultHandler arm local
    mov         r1, #REG_BASE

    @ Get IE & IF
    ldr         r0, [r1, #OFF_IE]!
    and         r0, r0, r0, lsr #16

    @ Ack IF
    strh        r0, [r1, #OFF_IE_IF]

    @ Ack IFBIOS
    ldr         r2, [r1, #OFF_IE_IFBIOS]
    orr         r2, r2, r0
    str         r2, [r1, #OFF_IE_IFBIOS]

    @ Check if we have a callback registered for these irqs
    ldr         r2, =IRQ_TABLE
    ldr         r3, [r2, #IRQ_TABLE_IRQSET]
    tst         r0, r3
    bxeq        lr

    @ Fast search
1:
    ldr         r3, [r2], #8
    tst         r0, r3
    bne         1b

.Ldispatch:
    @ Disable IME (r12)
    ldr         r12, [r1, #OFF_IME]
    str         r1, [r1, #OFF_IME]

    mrs         r3, spsr
    msr         cpsr_c, #0x5F
    @ MEM_IO, SPSR_irq, REG_IME, LR
    push        {r1, r3, r12, lr}

    ldr         r2, [r2, #-4]
    mov         lr, pc
    bx          r2

    pop         {r1, r3, r12, lr}
    msr         cpsr_c, #0xD2
    msr         spsr, r3

    str         r12, [r1, #OFF_IME]

    bx          lr
endfn

fn irqSimpleHandler arm local
    mov         r1, #REG_BASE

    @ Get IE & IF
    ldr         r0, [r1, #OFF_IE]!
    and         r0, r0, r0, lsr #16

    @ Ack IF
    strh        r0, [r1, #OFF_IE_IF]

    @ Ack IFBIOS
    ldr         r2, [r1, #OFF_IE_IFBIOS]
    orr         r2, r2, r0
    str         r2, [r1, #OFF_IE_IFBIOS]

    ldr         r2, IRQ_CALLBACK_FN

    @ Disable IME (r12)
    ldr         r12, [r1, #OFF_IME]
    str         r1, [r1, #OFF_IME]

    mrs         r3, spsr
    msr         cpsr_c, #0x5F
    push        {r1, r3, r12, lr}

    mov         lr, pc
    bx          r2

    pop         {r1, r3, r12, lr}
    msr         cpsr_c, #0xD2
    msr         spsr, r3

    str         r12, [r1, #OFF_IME]
    bx          lr
IRQ_CALLBACK_FN:
    .word       0
endfn

fn irqStubHandler arm local
    mov         r1, #REG_BASE

    @ Get IE & IF
    ldr         r0, [r1, #OFF_IE]!
    and         r0, r0, r0, lsr #16

    @ Ack IF
    strh        r0, [r1, #OFF_IE_IF]

    @ Ack IFBIOS
    ldr         r2, [r1, #OFF_IE_IFBIOS]
    orr         r2, r2, r0
    str         r2, [r1, #OFF_IE_IFBIOS]

    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
