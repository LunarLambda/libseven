.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.align          2
data IRQ_TABLE rw
    .fill       14, 8, 0
    .word       0
endd

@ r0    REG_BASE
@ r1    IE & IF
@ r2    <tmp>
@ r3    <tmp>
@ r12   IME
func irqDefaultHandler arm .iwram
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
    str         r12, [r1, #8]
    bx          lr
endf

func irqEnable thumb
    @ IME OFF
    ldr         r1, =0x04000200
    ldr         r2, [r1, #8]
    str         r1, [r1, #8]

    @ IE
    ldrh        r3, [r1]
    orrs        r0, r0, r3
    strh        r0, [r1]

    movs        r0, r3

    @ IME Restore
    str         r2, [r1, #8]

    bx          lr
endf

func irqDisable thumb
    @ IME OFF
    ldr         r1, =0x04000200
    ldr         r2, [r1, #8]
    str         r1, [r1, #8]

    @ IE
    ldrh        r3, [r1]
    bics        r0, r0, r3
    strh        r0, [r1]

    movs        r0, r3

    @ IME Restore
    str         r2, [r1, #8]

    bx          lr
endf

func irqSetEnabled thumb
    @ IME OFF
    ldr         r1, =0x04000200
    ldr         r2, [r1, #8]
    str         r1, [r1, #8]

    @ IE
    ldrh        r3, [r1]
    strh        r0, [r1]

    movs        r0, r3

    @ IME Restore
    str         r2, [r1, #8]

    bx          lr
endf

@ vim:ft=armv4 et sta sw=4 sts=8
