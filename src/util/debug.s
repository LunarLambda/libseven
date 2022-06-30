@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

fn dbgRaiseException arm .section=.text
    cmp r0, #5
    movhs r0, #0
    bxhs lr

    adr r1, EXCEPT_TABLE
    ldr r1, [r1, r0, lsl #2]

    @ prepare new cpsr
    @ r2 = old psr
    @ r0 = new psr
    mrs r2, cpsr
    bic r0, r2, #0x1F
    orr r0, r0, r1

    msr cpsr_c, r0
    msr spsr, r2

    ands r3, r1, #0xFF00

    @ Calculate offset for trigger instruction
    add lr, pc, r1, lsr #16

    @ "Trigger Instruction"
    mov pc, r3, lsr #8

    @ All LR values must be relative to this instruction, since no instruction
    @ Actually gets truly interrupted
    mov r0, #1
    bx lr

EXCEPT_TABLE:
    .word 0x00 << 16 | 0x04 << 8 | 0x1b | 0x80 @ undefined
    .word 0x04 << 16 | 0x0C << 8 | 0x17 | 0x80 @ prefetch abort
    .word 0x08 << 16 | 0x10 << 8 | 0x17 | 0x80 @ data abort
    .word 0x04 << 16 | 0x18 << 8 | 0x12 | 0x80 @ irq
    .word 0x04 << 16 | 0x1C << 8 | 0x11 | 0xC0 @ fiq
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
