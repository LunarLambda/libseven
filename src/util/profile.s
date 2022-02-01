@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/timer.s"

@ u32 profileFunction(void (*f)(void), u32 *return_value);
@
fn profileFunction arm
    push        {r4, r5, r6, lr}

    ldr         r4, =REG_TM2VAL
    mov         r5, #0
    mov         r6, r1

    @ REG_TM2VAL = 0
    @ REG_TM3VAL = 0
    strh        r5, [r4]
    strh        r5, [r4, #4]
    @ REG_TM3CNT
    mov         r2, TIMER_FREQ_CASCADE
    strh        r2, [r4, #6]
    @ REG_TM2CNT
    mov         r2, TIMER_ENABLE
    strh        r2, [r4, #2]

    @ Call fntion
    mov         lr, pc
    bx          r0

    @ Stop timer
    strh        r5, [r4, #2]

    @ Store return value?
    movs        r6, r6
    beq         .Lskip
    str         r0, [r6]
.Lskip:

    @ Read timers
    ldrh        r0, [r4]
    ldrh        r1, [r4, #4]
    orr         r0, r0, r1, lsl #16

    pop         {r4, r5, r6, lr}
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
