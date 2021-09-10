.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

func dmaCopy thumb
    mov         r12, r4
    @ r3 |= DMA_ENABLE
    movs        r4, #1
    lsls        r4, r4, #15
    orrs        r3, r3, r4
    @ r2 |= r3 << 16
    lsls        r3, r3, #16
    orrs        r2, r2, r3
    @ fire
    ldr         r4, =0x040000D4
    stm         r4!, {r0, r1, r2}
    mov         r4, r12
    bx          lr
endf
