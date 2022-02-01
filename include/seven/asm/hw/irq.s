@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_IRQ_S
.equiv   _LIBSEVEN_ASM_HW_IRQ_S, 1

.include "seven/asm/base.s"

REG     IE,             0x04000200
REG     IF,             0x04000202
REG     IME,            0x04000208
REG     IFBIOS,         0x03FFFFF8

CONST   IRQ_HANDLER,    0x03FFFFFC

BIT     IRQ_VBLANK,     0
BIT     IRQ_HBLANK,     1
BIT     IRQ_VCOUNT,     2
BIT     IRQ_TIMER_0,    3
BIT     IRQ_TIMER_1,    4
BIT     IRQ_TIMER_2,    5
BIT     IRQ_TIMER_3,    6
BIT     IRQ_SERIAL,     7
BIT     IRQ_DMA_0,      8
BIT     IRQ_DMA_1,      9
BIT     IRQ_DMA_2,      10
BIT     IRQ_DMA_3,      11
BIT     IRQ_KEYPAD,     12
BIT     IRQ_CARTRIDGE,  13

CONST   IRQS_BLANK,     IRQ_VBLANK  | IRQ_HBLANK
CONST   IRQS_TIMER,     IRQ_TIMER_0 | IRQ_TIMER_1 | IRQ_TIMER_2   | IRQ_TIMER_3
CONST   IRQS_DMA,       IRQ_DMA_0   | IRQ_DMA_1   | IRQ_DMA_2     | IRQ_DMA_3
CONST   IRQS_EXTERNAL,  IRQ_SERIAL  | IRQ_KEYPAD  | IRQ_CARTRIDGE
BITS    IRQS_ALL,       14

CONST   IRQ_INDEX_VBLANK,       0
CONST   IRQ_INDEX_HBLANK,       1
CONST   IRQ_INDEX_VCOUNT,       2
CONST   IRQ_INDEX_TIMER_0,      3
CONST   IRQ_INDEX_TIMER_1,      4
CONST   IRQ_INDEX_TIMER_2,      5
CONST   IRQ_INDEX_TIMER_3,      6
CONST   IRQ_INDEX_SERIAL,       7
CONST   IRQ_INDEX_DMA_0,        8
CONST   IRQ_INDEX_DMA_1,        9
CONST   IRQ_INDEX_DMA_2,        10
CONST   IRQ_INDEX_DMA_3,        11
CONST   IRQ_INDEX_KEYPAD,       12
CONST   IRQ_INDEX_CARTRIDGE,    13

EXTFN   irqInit
EXTFN   irqInitDefault
EXTFN   irqInitSimple
EXTFN   irqInitStub
EXTFN   irqCallbackSet
EXTFN   irqCallbackDelete
EXTFN   irqCallbackLookup
EXTFN   irqEnable
EXTFN   irqDisable
EXTFN   irqEnableFull
EXTFN   irqDisableFull
EXTFN   irqCriticalSectionEnter
EXTFN   irqCriticalSectionExit
EXTFN   irqCriticalSectionActive

.endif @ !_LIBSEVEN_ASM_HW_IRQ_S

@ vim: ft=armv4 et sta sw=4 sts=8
