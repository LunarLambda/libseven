@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"

@ TODO: Make all functions return a byte count

fn sramReadCore arm local
    ldrb        r3, [r2], #1
    strb        r3, [r0], #1
    cmp         r2, r1
    bne         sramReadCore
    bx          lr
endfn

fn sramRead64 thumb
    movs        r2, #0
fn sramReadAt64
    movs        r3, #64
    lsls        r3, r3, #10
    b           .Lsra_main
fn sramRead
    movs        r2, #0
fn sramReadAt
    movs        r3, #32
    lsls        r3, r3, #10
.Lsra_main:
    @ Length check
    cmp         r1, #0
    beq         .Lsra_ret
    @ Overflow check
    adds        r1, r1, r2
    bcs         .Lsra_ret
    @ Bounds check
    cmp         r1, r3
    bgt         .Lsra_ret

    @ r1 = sram_end
    @ r2 = sram_start
    movs        r3, #0xE
    lsls        r3, r3, #24

    adds        r1, r1, r3
    adds        r2, r2, r3

    ldr         r3, =sramReadCore
    @ Tailcall
    bx          r3
.Lsra_ret:
    bx          lr
endfn

@ void sramWriteAt(const void *src, u32 len, u32 off);
fn sramWrite64 thumb
    movs        r2, #0
fn sramWriteAt64
    movs        r3, #64
    lsls        r3, r3, #10
    b           .Lswa_main
fn sramWrite
    movs        r2, #0
fn sramWriteAt
    movs        r3, #64
    lsls        r3, r3, #10
.Lswa_main:
    @ Length check
    cmp         r1, #0
    beq         .Lswa_ret
    @ Overflow check
    adds        r1, r1, r2
    bcs         .Lswa_ret
    @ Bounds check
    cmp         r1, r3
    bgt         .Lswa_ret

    @ r1 = sram_end
    @ r2 = sram_start
    movs        r3, #0xE
    lsls        r3, r3, #24
    adds        r1, r1, r3
    adds        r2, r2, r3

.Lswa_loop:
    ldrb        r3, [r0]
    strb        r3, [r2]
    adds        r0, r0, #1
    adds        r2, r2, #1
    cmp         r2, r1
    bne         .Lswa_loop

.Lswa_ret:
    bx          lr
endfn

@ src, offset, sram/temp2, counter, temp

@ rX = src
@ rY = sram

@ rT = temp, end addr
@ rU = temp2

@ r0 = src
@ r2 = sram_start
@ r1 = length

@ r3, r12 = temp
@1:
@ldrb    temp1, [lhs, counter]
@ldrb    temp2, [rhs, counter]
@cmp     temp1, temp2
@bxeq    lr
@add     counter, #1
@cmp     counter, max
@bne     1b


fn sramCompareCore arm local
.Lscc_loop:
    ldrb        r3, [r0]
    ldrb        r12, [r2]
    cmp         r3, r12
    @ branch
    add         r0, r0, #1
    add         r2, r2, #1

    bx          lr
endfn

@ void sramCompareAt(const void *src, u32 len, u32 off);
fn sramCompare64 thumb
    movs        r2, #0
fn sramCompareAt64
    movs        r3, #64
    lsls        r3, r3, #10
    b           .Lswc_main
fn sramCompare
    movs        r2, #0
fn sramCompareAt
    movs        r3, #64
    lsls        r3, r3, #10
.Lswc_main:
    @ Length check
    cmp         r1, #0
    beq         .Lswc_ret
    @ Overflow check
    adds        r1, r1, r2
    bcs         .Lswc_ret
    @ Bounds check
    cmp         r1, r3
    bgt         .Lswc_ret
    subs        r1, r1, r2

    @ r0 = src
    @ r1 = sram_end
    @ r2 = sram_addr
    movs        r3, #0xE
    lsls        r3, r3, #24
    adds        r1, r1, r3
    adds        r2, r2, r3
    ldr         r3, =sramCompareCore
    @ Tail call
    bx          r3
.Lswc_ret:
    bx          lr
endfn

fn sramClear64 thumb
    movs        r1, #0
fn sramClearAt64
    movs        r3, #64
    lsls        r3, r3, #10
    b           .Lsza_main
fn sramClear
    movs        r1, #0
fn sramClearAt
    movs        r3, #32
    lsls        r3, r3, #10
    @ Length check
    cmp         r0, #0
    beq         .Lsza_oob
    @ Overflow check
    adds        r2, r0, r1
    bcs         .Lsza_oob
    @ Bounds check
    cmp         r2, r3
    bgt         .Lsza_oob

    @ r1 += MEM_SRAM
    movs        r3, #0xE
    lsls        r3, r3, #24
    adds        r1, r1, r3

    @ r0 = len
    @ r1 = *dst
    @ r2 = 0
    @ r3 = count

    @ loop
    movs        r2, #0
    movs        r3, #0
.Lsza_loop:
    strb        r2, [r1, r3]
    adds        r3, r3, #1
    cmp         r3, r0
    bne         .Lsza_loop

.Lsza_oob:
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
