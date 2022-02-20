/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_TIMER_H
#define _LIBSEVEN_HW_TIMER_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_TM0VAL      VOLADDR(0x04000100, u16)
#define REG_TM0CNT      VOLADDR(0x04000102, u16)

#define REG_TM1VAL      VOLADDR(0x04000104, u16)
#define REG_TM1CNT      VOLADDR(0x04000106, u16)

#define REG_TM2VAL      VOLADDR(0x04000108, u16)
#define REG_TM2CNT      VOLADDR(0x0400010A, u16)

#define REG_TM3VAL      VOLADDR(0x0400010C, u16)
#define REG_TM3CNT      VOLADDR(0x0400010E, u16)

#define BF_TIMER_FREQ_OFFSET 0
#define BF_TIMER_FREQ_LENGTH 3

#define TIMER_FREQ(n) BITFIELD(TIMER_FREQ, (n))

enum TimerControl
{
    TIMER_FREQ_16MHZ    = TIMER_FREQ(0),
    TIMER_FREQ_262KHZ   = TIMER_FREQ(1),
    TIMER_FREQ_64KHZ    = TIMER_FREQ(2),
    TIMER_FREQ_16KHZ    = TIMER_FREQ(3),
    TIMER_FREQ_CASCADE  = TIMER_FREQ(4),
    TIMER_IRQ_ENABLE    = BIT(6),
    TIMER_ENABLE        = BIT(7),
};

extern void timerSet(u32 num, u16 reload, u16 flags);

extern void timerEnable(u32 num);

extern void timerDisable(u32 num);

extern u16 timerGetValue(u32 num);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_TIMER_H */
