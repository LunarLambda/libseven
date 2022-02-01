@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_TIMER_S
.equiv   _LIBSEVEN_ASM_HW_TIMER_S, 1

.include "seven/asm/base.s"

REG      TM0VAL, 0x04000100
REG      TM0CNT, 0x04000102
REG      TM1VAL, 0x04000104
REG      TM1CNT, 0x04000106
REG      TM2VAL, 0x04000108
REG      TM2CNT, 0x0400010A
REG      TM3VAL, 0x0400010C
REG      TM3CNT, 0x0400010E

CONST    BF_TIMER_FREQ_OFFSET, 0
CONST    BF_TIMER_FREQ_LENGTH, 3

BITFIELD TIMER_FREQ 16MHZ,     0
BITFIELD TIMER_FREQ 262KHZ,    1
BITFIELD TIMER_FREQ 64KHZ,     2
BITFIELD TIMER_FREQ 16KHZ,     3
BITFIELD TIMER_FREQ CASCADE,   4
BIT      TIMER_IRQ_ENABLE,     6
BIT      TIMER_ENABLE,         7

EXTFN    timerSet
EXTFN    timerEnable
EXTFN    timerDisable
EXTFN    timerGetValue

.endif @ !_LIBSEVEN_ASM_HW_TIMER_S

@ vim: ft=armv4 et sta sw=4 sts=8
