@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/input.s"

bss KEYINPUT
    .word 0
endb

fn inputPoll thumb
    @ ~REG_KEYINPUT & 0x3FFF
    ldr         r0, =REG_KEYINPUT
    ldrh        r0, [r0]
    mvns        r0, r0
    lsls        r0, r0, #22
    lsrs        r0, r0, #22
    ldr         r1, =KEYINPUT
    ldr         r2, [r1]
    lsls        r2, r2, #16
    orrs        r2, r2, r0
    str         r2, [r1]
    bx          lr
endfn

fn inputState thumb
    ldr         r0, =KEYINPUT
    ldr         r0, [r0]
    bx          lr
endfn

fn inputKeysPressed thumb
    ldr         r1, =KEYINPUT
    ldr         r1, [r1]
    lsrs        r2, r1, #16
    bics        r1, r1, r2
    ands        r0, r0, r1
    bx          lr
endfn

fn inputKeysReleased thumb
    ldr         r1, =KEYINPUT
    ldr         r1, [r1]
    lsrs        r2, r1, #16
    bics        r2, r2, r1
    ands        r0, r0, r2
    bx          lr
endfn

fn inputKeysDown thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    ands        r0, r0, r1
    bx          lr
endfn

fn inputKeysUp thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    bics        r0, r0, r1
    bx          lr
endfn

fn inputAxisX thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    movs        r0, #0
    lsls        r1, r1, #31 - KEY_INDEX_LEFT
    @ C = RIGHT, r1 = -1 if LEFT, else 0
    asrs        r1, r1, #31
    @ 0 - LEFT + RIGHT
    adcs        r0, r0, r1
    bx          lr
endfn

fn inputAxisY thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    movs        r0, #0
    @ C = UP, r1 = -1 if DOWN, else 0
    lsls        r1, r1, #31 - KEY_INDEX_DOWN
    asrs        r1, r1, #31
    @ r0 = 0 + -DOWN + UP
    adcs        r0, r0, r1
    negs        r0, r0
    bx          lr
endfn

fn inputAxisLR thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    movs        r0, #0
    @ C = R, r1 = -1 if L, else 0
    lsls        r1, r1, #31 - KEY_INDEX_L
    asrs        r1, r1, #31
    @ r0 = 0 + -L + R
    adcs        r0, r0, r1
    bx          lr
endfn

fn inputAxisAB thumb
    ldr         r1, =KEYINPUT
    ldrh        r1, [r1]
    movs        r0, #0
    @ C = A, r1 = -1 if B, else 0
    lsls        r1, r1, #31 - KEY_INDEX_B
    asrs        r1, r1, #31
    @ r0 = 0 + -B + A
    adcs        r0, r0, r1
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
