@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

@ Memory Copy

fn memCopy8 thumb
    bx          lr
endfn

fn memCopy16 thumb
    bx          lr
endfn

fn memCopy32 arm
    bx          lr
endfn

@ Memory Move

fn memMove8 thumb
    bx          lr
endfn

fn memMove16 thumb
    bx          lr
endfn

fn memMove32 arm
    bx          lr
endfn

@ Memory Set

fn memSet8 thumb
    bx          lr
endfn

fn memSet16 thumb
    bx          lr
endfn

fn memSet32 arm
    bx          lr
endfn

@ Memory Zero

fn memZero8 thumb
    movs        r2, r1
    movs        r1, #0
    b           memSet8
endfn

fn memZero16 thumb
    movs        r2, r1
    movs        r1, #0
    b           memSet16
endfn

fn memZero32 arm
    movs        r2, r1
    movs        r1, #0
    b           memSet32
endfn

@ Memory Compare

fn memCompare8 thumb
    bx          lr
endfn

fn memCompare16 thumb
    bx          lr
endfn

fn memCompare32 arm
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
