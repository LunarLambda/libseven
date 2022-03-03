@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

@ usize oamWriteObjects(usize oam_index, struct Object *obj, usize n_objs)
@
fn oamWriteObjects thumb
    adds        r3, r0, r2
    bcs         .Lo_truncate

    cmp         r3, #128
    ble         oamWriteObjectsUnchecked

.Lo_truncate:
    movs        r3, #128
    subs        r2, r3, r0
    bmi         .Lo_exit0

fn oamWriteObjectsUnchecked
    push        {r4, r5}
    
    movs        r5, r2
    beq         .Lo_exit

    lsls        r0, r0, #3
    lsls        r2, r2, #3

    @ r0 += MEM_OAM
    movs        r3, #7
    lsls        r3, r3, #24

    adds        r0, r0, r3
    @ End pointer
    adds        r2, r2, r1
    @ r0: dst, r1: src, r2: end

.Lo_loop:
    ldm         r1!, {r3, r4}
    str         r3, [r0]
    strh        r4, [r0, #4]
    adds        r0, #8
    cmp         r1, r2
    bne         .Lo_loop

.Lo_exit:
    movs        r0, r5
    pop         {r4, r5}
    bx          lr
.Lo_exit0:
    movs        r0, #0
    bx          lr
endfn

@ usize oamWriteMatrices(usize oam_index, struct Matrix *mat, usize n_mats)
fn oamWriteMatrices thumb
    adds        r3, r0, r2
    bcs         .Lm_truncate

    cmp         r3, #32
    ble         oamWriteMatricesUnchecked

.Lm_truncate:
    movs        r3, #32
    subs        r2, r3, r0
    bmi         .Lm_exit0

fn oamWriteMatricesUnchecked
    push        {r4, r5}
    movs        r5, r2
    beq         .Lm_exit

    lsls        r0, r0, #5
    lsls        r2, r2, #3

    @ r0 += MEM_OAM
    movs        r3, #7
    lsls        r3, r3, #24

    @ OAM pointer
    adds        r0, r0, r3
    @ End pointer
    adds        r2, r2, r1
    @ r0: dst, r1: src, r2: end

.Lm_loop:
    ldm         r1!, {r3, r4}
    strh        r3, [r0, #0+6]
    lsrs        r3, r3, #16
    strh        r3, [r0, #8+6]
    strh        r4, [r0, #16+6]
    lsrs        r4, r4, #16
    strh        r4, [r0, #24+6]
    adds        r0, #32
    cmp         r1, r2
    bne         .Lm_loop

.Lm_exit:
    movs        r0, r5
    pop         {r4, r5}
    bx          lr
.Lm_exit0:
    movs        r0, #0
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
