.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.set MEM_SRAM,          0x0E000000
.set MEM_SRAM_SIZE,     0x8000

@ TODO: Reduce IWRAM use by only running core sram-read loops in RAM
@ Use subfn to improve size & performance.
@
@ Save a register by using start + end pointers instead of pointers + count

@ r0 = dst, r1 = len
fn sramRead arm
    mov         r2, #0
    b           sramReadAt
endfn

@ r0 = u8* dst
@ r1 = u32 len
@ r2 = u32 off
fn sramReadAt arm
    @ Bounds check
    add         r3, r1, r2
    cmp         r3, #0x8000
    bgt         .Lsra_oob

    add         r2, r2, MEM_SRAM
    @ r0 = dst
    @ r1 = len
    @ r2 = src

    mov         r3, #0
    cmp         r1, #0
    beq         .Lsra_oob

    @ r3 = count
    @ r12 = temp
.Lsra_loop:
    ldrb        r12, [r2, r3]
    strb        r12, [r0, r3]
    add         r3, r3, #1
    cmp         r1, r3
    bne         .Lsra_loop

.Lsra_oob:
    bx          lr
endfn

fn sramWrite thumb
    movs        r2, #0
    b           sramWriteAt
endfn

@ r0 = const u8 *src
@ r1 = u32 len
@ r2 = u32 off
fn sramWriteAt thumb
    push        {r4, r5}

    @ Bounds check (len + off <= MEM_SRAM_SIZE)
    movs        r4, #0x80
    lsls        r4, r4, #8
    adds        r3, r1, r2
    cmp         r3, r4
    bgt         .Lswa_oob

    @ r2 += MEM_SRAM
    movs        r4, #0xE
    lsls        r4, r4, #24
    adds        r2, r2, r4

    @ loop
    movs        r3, #0
    cmp         r1, #0
    beq         .Lswa_oob
.Lswa_loop:
    ldrb        r4, [r0, r3]
    strb        r4, [r2, r3]
    adds        r3, r3, #1
    cmp         r3, r1
    bne         .Lswa_loop

.Lswa_oob:
    pop         {r4, r5}
    bx          lr
endfn

fn sramCompare arm
    mov         r2, #0
    b           sramCompareAt
endfn

fn sramCompareAt arm
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
endfn

fn sramClear thumb
    movs        r1, #0
    b           sramClearAt
endfn

fn sramClearAt thumb
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
endfn

@ vim:ft=armv4 et sta sw=4 sts=8
