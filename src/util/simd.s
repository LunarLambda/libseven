@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

@ r0 = mask
@ r1 = dst
@ r2 = src
@ r3 = len
@ r4 = a
@ r5 = b
@ r6 = s
fn simdAdd thumb
    push        {r4, r5, r6, r7}

    cmp         r3, #0
    beq         2f

    adds        r3, r1, r3
1:
    ldr         r4, [r1]
    ldm         r2!, {r5}
    @ s = (a ^ b) & m
    movs        r6, r4
    eors        r6, r6, r5
    ands        r6, r6, r0
    @ a &= ~m
    @ b &= ~m
    bics        r4, r4, r0
    bics        r5, r5, r0
    @ a = (a + b) ^ s
    adds        r4, r4, r5
    eors        r4, r4, r6

    stm         r1!, {r4}
    cmp         r1, r3
    blt         1b
2:
    pop         {r4, r5, r6, r7}
    bx          lr
endfn

fn simdSub thumb
    push        {r4, r5, r6, r7}

    cmp         r3, #0
    beq         2f

    adds        r3, r1, r3

1:
    ldr         r4, [r1]
    ldm         r2!, {r5}
    @ s = (~a ^ b) & m
    mvns        r6, r4
    eors        r6, r6, r5
    ands        r6, r6, r0
    @ a |=  m
    @ b &= ~m
    orrs        r4, r4, r0
    bics        r5, r5, r0
    @ a = (a - b) ^ s
    subs        r4, r4, r5
    eors        r4, r4, r6

    stm         r1!, {r4}
    cmp         r1, r3
    blt         1b

2:
    pop         {r4, r5, r6, r7}
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
