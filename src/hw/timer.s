@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/timer.s"

fn timerSet thumb
    cmp         r0, #3
    bgt         1f

    lsls        r0, r0, #2
    lsls        r2, r2, #16
    orrs        r2, r2, r1

    ldr         r3, =REG_TM0VAL
    str         r2, [r3, r0]
1:
    bx          lr
endfn

fn timerEnable thumb
    cmp         r0, #3
    bgt         1f

    lsls        r0, r0, #2
    movs        r1, TIMER_ENABLE
    ldr         r2, =REG_TM0CNT

    ldrh        r3, [r2, r0]
    orrs        r3, r3, r1
    strh        r3, [r2, r0]
1:
    bx          lr
endfn

fn timerDisable thumb
    cmp         r0, #3
    bgt         1f

    lsls        r0, r0, #2
    movs        r1, TIMER_ENABLE
    ldr         r2, =REG_TM0CNT

    ldrh        r3, [r2, r0]
    bics        r3, r3, r1
    strh        r3, [r2, r0]
1:
    bx          lr
endfn

fn timerGetValue thumb
    cmp         r0, #3
    bgt         1f

    lsls        r0, r0, #2
    ldr         r1, =REG_TM0VAL
    ldrh        r0, [r1, r0]
    bx          lr
1:
    movs        r0, #0
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
