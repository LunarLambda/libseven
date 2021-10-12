.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.set REG_DMA0, 0x040000B0
.set REG_DMA1, 0x040000BC
.set REG_DMA2, 0x040000C8
.set REG_DMA3, 0x040000D4

.set REG_DMACNT, 0x040000BA

@ r0: num
func dmaEnable thumb
    cmp         r0, #3
    bgt         .Leout

    @ * 8
    lsls        r1, r0, #3
    @ * 4
    lsls        r0, r0, #2
    @ = * 12
    adds        r0, r0, r1

    @ Read DMACNT
    ldr         r1, =REG_DMACNT
    ldrh        r2, [r1, r0]

    @ Add DMA_ENABLE
    movs        r3, #0x80
    lsls        r3, r3, #8
    orrs        r2, r2, r3

    strh        r2, [r1, r0]
.Leout:
    bx          lr
endf

func dmaDisable thumb
    cmp         r0, #3

    bgt         .Ldout
    @ * 8
    lsls        r1, r0, #3
    @ * 4
    lsls        r0, r0, #2
    @ = * 12
    adds        r0, r0, r1

    @ Read DMACNT
    ldr         r1, =REG_DMACNT
    ldrh        r2, [r1, r0]

    @ Remove DMA_ENABLE
    movs        r3, #0x80
    lsls        r3, r3, #8
    bics        r2, r2, r3

    strh        r2, [r1, r0]
.Ldout:
    bx          lr
endf

@ r0: src
@ r1: dst
func dmaCopy16 thumb
    @ DMA_ENABLE
    movs        r3, #0x80
    lsls        r3, r3, #24
    @ len = (len / 2) & 0xFFFF
    lsls        r2, r2, #15
    lsrs        r2, r2, #16
    orrs        r2, r2, r3
    ldr         r3, =REG_DMA3
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

@ r0: src
@ r1: dst
func dmaCopy32 thumb
    @ DMA_ENABLE | DMA_32BIT
    movs        r3, #0x84
    lsls        r3, r3, #24
    @ len = (len / 4) & 0xFFFF
    lsls        r2, r2, #14
    lsrs        r2, r2, #16
    orrs        r2, r2, r3
    ldr         r3, =REG_DMA3
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

@ r0: src
@ r1: flags
func dmaSoundFifoATransfer thumb
    lsls        r3, r1, #16
    ldr         r1, =0x040000A0
    @ DMA_REPEAT | DMA_START_SOUND
    movs        r2, #0x32
    lsls        r2, r2, #24
    orrs        r2, r2, r3
    ldr         r3, =REG_DMA1
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

@ r0: src
@ r1: flags
func dmaSoundFifoBTransfer thumb
    lsls        r3, r1, #16
    ldr         r1, =0x040000A4
    movs        r2, #0x32
    lsls        r2, r2, #24
    orrs        r2, r2, r3
    ldr         r3, =REG_DMA2
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

@ r0: src
@ r1: dst
@ r2: count
@ r3: flags
func dmaHBlankTransfer thumb
    @ Clear DMA_START flags
    mov         r12, r4
    movs        r4, #0x30
    lsls        r4, r4, #8
    bics        r3, r3, r4
    @ Add DMA_START_HBLANK | DMA_REPEAT
    movs        r4, #0x22
    lsls        r4, r4, #8
    orrs        r3, r3, r4
    @ Check for DMA_32BIT and adjust byte count
    lsrs        r4, r3, #11
    mov         r4, r12
    bcs         1f
    lsls        r2, r2, #1
1:
    lsls        r2, r2, #14
    lsrs        r2, r2, #16

    lsls        r3, r3, #16
    orrs        r2, r2, r3
    ldr         r3, =REG_DMA0
    stm         r3!, {r0, r1, r2}
    bx          lr
endf

@ r0: num
@ r1: src
@ r2: dst
@ r3: len
@ [sp]: flags
func dmaSet thumb
    cmp         r0, #3
    bgt         .Lsout
    push        {r4, r5}

    @ num *= 12
    lsls        r4, r0, #3
    lsls        r0, r0, #2
    adds        r0, r0, r4

    @ Final Address
    ldr         r4, =REG_DMA0
    adds        r0, r0, r4

    @ Load flags
    ldr         r4, [sp]

    @ Adjust byte count
    lsrs        r5, r4, #11
    bcs         1f
    lsls        r3, r3, #1
1:
    lsls        r3, r3, #14
    lsrs        r3, r3, #16

    @ Merge Length and Flags
    lsls        r4, r4, #16
    orrs        r3, r3, r4

    stm         r0!, {r1, r2, r3}

    pop         {r4, r5}
.Lsout:
    bx          lr
endf
