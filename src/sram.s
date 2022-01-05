@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.set MEM_SRAM,          0x0E000000
.set MEM_SRAM_SIZE,     0x8000

@ TODO: Make all functions return a byte count

fn sramReadCore arm local
    ldrb        r3, [r2], #1
    strb        r3, [r0], #1
    cmp         r2, r1
    bne         sramReadCore
    bx          lr
endfn

@ void sramReadAt(void *src, u32 len, u32 off);
fn sramRead thumb
    movs        r2, #0
sfn sramReadAt
    @ Return if len == 0
    cmp         r1, #0
    beq         .Lsra_ret

    @ len += off
    adds         r1, r1, r2
    @ r3 = 0x8000
    movs        r3, #0x80
    lsls        r3, r3, #8
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
endsfn
endfn

@ void sramWriteAt(const void *src, u32 len, u32 off);
fn sramWrite thumb
    movs        r2, #0
sfn sramWriteAt
    cmp         r1, #0
    beq         .Lswa_ret

    @ len += off
    adds        r1, r1, r2
    @ Bounds check
    movs        r3, #0x80
    lsls        r3, r3, #8
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
endsfn
endfn


@ TODO: Reduce IWRAM use by only running core sram-read loops in RAM
@
@ Save a register by using start + end pointers instead of pointers + count
@ u32 sramCompareAt(const void *src, u32 len, u32 off);

fn sramCompare arm
    mov         r2, #0
sfn sramCompareAt
    push        {r4, r5}

    mov         r3, r0
    mov         r0, #0

    @ if len = 0
    cmp         r1, #0
    beq         .Lsca_out

    @ Bounds check
    add         r4, r1, r2
    cmp         r4, #0x8000
    bgt         .Lsca_out

    add         r2, r2, MEM_SRAM

    @ r0 = count
    @ r1 = len
    @ r2 = rhs
    @ r3 = lhs
    @ r5 = temp_rhs
    @ r4 = temp_lhs
.Lsca_loop:
    ldrb        r4, [r2, r0]
    ldrb        r5, [r3, r0]

    cmp         r4, r5
    bne         .Lsca_out

    add         r0, r0, #1
    cmp         r1, r0
    bne         .Lsca_loop

.Lsca_out:
    pop         {r4, r5}
    bx          lr
endsfn
endfn

fn sramClear thumb
    movs        r1, #0
sfn sramClearAt
    @ if len = 0
    cmp         r0, #0
    beq         .Lsza_oob

    @ Bounds check (len + off <= MEM_SRAM_SIZE)
    movs        r3, #0x80
    lsls        r3, r3, #8
    adds        r2, r0, r1
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
endsfn
endfn

@ vim:ft=armv4 et sta sw=4 sts=8
