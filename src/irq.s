.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.align          2
data IRQ_TABLE rw
    .fill       16, 8, 0
endd

func irqDefaultHandler arm .iwram
    @ Save registers
    push        {r4, r5}

    mov         r4, #0x04000000

    @ Disable IME.
    @ An interrupt handler can later enable it again
    @ if it wishes to use nested interrupts.
    ldr         r5, [r4, #0x208]
    str         r4, [r4, #0x208]

    @ Determine interrupt cause(s).
    @ This is done by AND-ing IE and IF
    @ to get the interrupts that are "enabled AND flagged".
    ldr         r0, [r4, #0x200]
    and         r0, r0, r0, lsr #16

    @ Acknowledge the interrupts by writing this value to IF.
    ldr         r1, =#0x202
    strh        r0, [r4, r1]

    @ OR the value of "IFBIOS" (0x03FFFFF8)
    @ with this value to make IntrWait work.
    ldrh        r1, [r4, #-8]
    orr         r1, r1, r0
    strh        r1, [r4, #-8]

    @ Search for an appropriate handler function
    @ using this value.
    ldr         r1, =IRQ_TABLE
    mvn         r2, #2
.Lsearch:
    ldr         r3, [r1], #8
    tst         r0, r3
    bne         .Ldispatch
    lsls        r2, r2, #2
    tst         r3, r3
    bhi         .Lsearch
    b           .Lexit

.Ldispatch:
    @ Save SPSR_irq, Switch to System Mode, save lr
    @
    @ Saving the SPSR is required for nested interrupts to work as it would
    @ otherwise be overwritten by another IRQ entry.
    @
    @ Saving the system mode LR register is necessary because we use it here.
    mrs         r12, spsr
    msr         cpsr_c, #0x5F
    push        {r12, lr}

    @ Call handler
    ldr         r1, [r1, #-4]
    mov         lr, pc
    bx          r1

.Lcleanup:
    @ Return to IRQ Mode, restoring LR and the SPSR.
    pop         {r12, lr}
    msr         cpsr_c, #0xD2
    msr         spsr, r12

.Lexit:
    @ Restore IME to its previous value, and restore the registers we saved.
    str         r5, [r4, #0x208]
    pop         {r4, r5}
    bx          lr
endf

@ vim:ft=armv4 et sta sw=4 sts=8
