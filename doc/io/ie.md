# I/O Register Reference - Interrupt Enable

Defined in [seven/hw/irq.h](../../include/seven/hw/irq.h)

Address   | Size | Access | GBATEK | libgba | libtonc | libseven
:--------:|:----:|:------:|:-------|:-------|:--------|:--------
0400 0200 | 16   | R/W    | IE     | IE     | IE      | IE

## Contents

 Bits | Description                 | C Constants
-----:|:----------------------------|:-----------
 0    | Start of V-Blank            | IRQ_VBLANK
 1    | Start of H-Blank            | IRQ_HBLANK
 2    | Scanline counter match      | IRQ_VCOUNT
 3    | Timer 0 overflow            | IRQ_TIMER_0
 4    | Timer 1 overflow            | IRQ_TIMER_1
 5    | Timer 2 overflow            | IRQ_TIMER_2
 6    | Timer 3 overflow            | IRQ_TIMER_3
 7    | Serial communication        | IRQ_SERIAL
 8    | DMA 0 transfer completion   | IRQ_DMA_0
 9    | DMA 1 transfer completion   | IRQ_DMA_1
10    | DMA 2 transfer completion   | IRQ_DMA_2
11    | DMA 3 transfer completion   | IRQ_DMA_3
12    | D-pad/button input          | IRQ_KEYPAD
13    | Cartridge interrupt request | IRQ_CARTRIDGE
14-15 | -                           | -
