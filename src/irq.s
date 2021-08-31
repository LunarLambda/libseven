.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

@ BIOS IRQ sequence looks as follows:
@
@ 0018 b                IRQ
@
@ IRQ:
@ 0128 stmdb            sp!, {r0-r3, r12, lr}
@ 012c mov              r0, #MEM_IO
@ 0130 adr              lr, #0x138
@ 0134 ldr              pc, [r0, #-4] => IRQ_USER_HANDLER
@ 0138 ldmia            sp!, {r0-r3, r12, lr}
@ 013c subs             pc, lr, #4
@
@ Handler always called in ARM state, best to have ISR in iwram
@ SPSR_irq and LR_irq set
@
@ CPSR I bit is set (irq disabled)
@ r0-r3, r12, r14_irq saved on IRQ stack
@ SPSR_irq not saved
@ IRQ stack has 34 words free
@ return by bx lr

.align          2
data IRQ_TABLE rw
    .fill       16, 8, 0
endd

func irqDefaultHandler arm .iwram
    push        {r4, r5}
    mov         r4, #0x04000000
    @ REG_IME = 0
    ldr         r5, [r4, #0x208]
    str         r4, [r4, #0x208]
    @ r0 = REG_IE & REG_IF
    ldr         r0, [r4, #0x200]
    and         r0, r0, r0, lsr #16
    @ REG_IF = r0
    ldr         r1, =#0x202
    strh        r0, [r4, r1]
    @ REG_IFBIOS |= r0
    ldrh        r1, [r4, #-8]
    orr         r1, r1, r0
    strh        r1, [r4, #-8]

    @ r0 = IE & IF
    @ r4 = MEM_IO
    @ r5 = IME

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
    mrs         r12, spsr
    msr         cpsr_c, #0x5F
    push        {r12, lr}

    @ Call handler
    ldr         r1, [r1, #-4]
    mov         lr, pc
    bx          r1

.Lcleanup:
    @ Return to IRQ Mode
    pop         {r12, lr}
    msr         cpsr_c, #0xD2
    msr         spsr, r12

.Lexit:
    str         r5, [r4, #0x208]
    pop         {r4, r5}
    bx          lr
endf

@ vim:ft=armv4 et sta sw=4 sts=8
