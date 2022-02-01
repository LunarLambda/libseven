@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

@ state cannot be all zeroes, generator locks up
@ set last state word as 1 to make sure SetSeed(0) is fine.
data XOSHIRO_STATE
    .word 0, 0, 0, 1
endd

@ void randSetSeed(u32 seed)
@
fn randSetSeed thumb
    ldr         r1, =XOSHIRO_STATE
    str         r0, [r1]
    bx          lr
endfn

@ u32 randNext(void)
@
@ Implementation of the Xoshiro128++ PRNG.
@
@ Excellent speed, entropy, and periodicity.
@
@ Code from https://xoshiro.di.unimi.it/xoshiro128plusplus.c
@
@ r0    return
@ r1    s[0]
@ r2    s[1]
@ r3    s[2]
@ r4    s[3]
@ r5    t
@ r6    &XOSHIRO_STATE
@ r7    ROR immediate
fn randNext thumb
    push        {r4, r5, r6, r7}

    ldr         r6, =XOSHIRO_STATE
    ldmia       r6!, {r1, r2, r3, r4}

    @ r = s[0] + s[3]
    adds        r0, r1, r4
    @ r = rotl(r, 7)
    movs        r7, #25
    rors        r0, r0, r7
    @ r += s[0]
    adds        r0, r0, r1

    @ t = s[1] << 9
    lsls        r5, r2, #9

    @ s[2] ^= s[0]
    eors        r3, r3, r1
    @ s[3] ^= s[1]
    eors        r4, r4, r2
    @ s[1] ^= s[2]
    eors        r2, r2, r3
    @ s[0] ^= s[3]
    eors        r1, r1, r4
    @ s[2] ^= t
    eors        r3, r3, r5

    @ s[3] = rotl(s[3], 11)
    movs        r7, #21
    rors        r4, r4, r7

    subs        r6, r6, #16
    stmia       r6!, {r1, r2, r3, r4}

    pop         {r4, r5, r6, r7}
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
