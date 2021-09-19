.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

func dmaTransfer arm .iwram
    @ r2 |= r3 << 16
    orr         r2, r2, r3, lsl #16
    @ r2 |= DMA_ENABLE
    orr         r2, r2, #0x80000000
    @ Fire on DMA3
    ldr         r3, =0x040000D4
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

func dmaHBlankTransfer arm .iwram
    @ r2 |= r3 << 16
    orr         r2, r2, r3, lsl #16
    @ Unset DMA_START bits
    bic         r2, r2, #0x30000000
    @ DMA_ENABLE | DMA_START_HBLANK
    orr         r2, r2, #0xA0000000
    @ Fire on DMA0
    ldr         r3, =0x040000B0
    stm         r3!, {r0, r1, r2}
    bx          lr
endf
