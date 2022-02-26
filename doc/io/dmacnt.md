# I/O Register Reference - DMA Control

Defined in [seven/hw/dma.h](../../include/seven/hw/dma.h)

Address     | Size | Access | GBATEK    | libgba | libtonc   | libseven
:----------:|:----:|:------:|:----------|:-------|:----------|:--------
 0400 00BA  | 16   | R/W    | DMA0CNT_H | -      | DMA0CNT_H | **DMA0CNT**
 0400 00C6  | 16   | R/W    | DMA1CNT_H | -      | DMA1CNT_H | **DMA1CNT**
 0400 00D2  | 16   | R/W    | DMA2CNT_H | -      | DMA2CNT_H | **DMA2CNT**
 0400 00DE  | 16   | R/W    | DMA3CNT_H | -      | DMA3CNT_H | **DMA3CNT**

## Contents

Bits  | Access | Description                        | C Constants
-----:|:------:|:-----------------------------------|:-----------
 0-4  | -      | -                                  | -
 5-6  | R/W    | Destination addressing mode        | DMA_DST_\*
 7-8  | R/W    | Source addressing mode             | DMA_SRC_\*
 9    | R/W    | Repeat transfer                    | DMA_REPEAT
10    | R/W    | Unit size (0 = 16-bit, 1 = 32-bit) | DMA_16BIT, DMA_32BIT
11    | R/W    | Respond to cartridge DMA request   | -
12-13 | R/W    | Start timing                       | DMA_START_\*
14    | R/W    | Trigger interrupt on completion    | DMA_IRQ_ENABLE
15    | R/W    | Enable DMA channel                 | DMA_ENABLE

## DMA_DST Bitfield

Value | Description                                           | C Constants
-----:|:------------------------------------------------------|:-----------
0     | Increment address                                     | DMA_DST_INCREMENT
1     | Decrement address                                     | DMA_DST_DECREMENT
2     | Do not change address                                 | DMA_DST_FIXED
3     | Increment address and reload register upon completion | DMA_DST_RELOAD

## DMA_SRC Bitfield

Value | Description           | C Constants
-----:|:----------------------|:-----------
0     | Increment address     | DMA_SRC_INCREMENT
1     | Decrement address     | DMA_SRC_DECREMENT
2     | Do not change address | DMA_SRC_FIXED

## DMA_START Bitfield

Value | Description                                         | C Constants
-----:|:----------------------------------------------------|:-----------
0     | Start immediately                                   | DMA_START_NOW
1     | Start at H-Blank                                    | DMA_START_HBLANK
2     | Start at V-Blank                                    | DMA_START_VBLANK
3     | Forbidden (DMA 0)                                   | -
3     | Start when sound FIFOs empty (DMA 1, DMA 2)         | DMA_START_SPECIAL / DMA_START_SOUND
3     | Start in scanline 2, run until scanline 162 (DMA 3) | DMA_START_SPECIAL / DMA_START_CAPTURE
