#ifndef _LIBSEVEN_HW_TIMER_H
#define _LIBSEVEN_HW_TIMER_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_TM0VAL      REG16(0x04000100)
#define REG_TM0CNT      REG16(0x04000102)

#define REG_TM1VAL      REG16(0x04000104)
#define REG_TM1CNT      REG16(0x04000106)

#define REG_TM2VAL      REG16(0x04000108)
#define REG_TM2CNT      REG16(0x0400010A)

#define REG_TM3VAL      REG16(0x0400010C)
#define REG_TM3CNT      REG16(0x0400010E)

enum TimerControl
{
    TIMER_FREQ_16MHZ    = BITFIELD(0, 3, 0),
    TIMER_FREQ_262KHZ   = BITFIELD(0, 3, 1),
    TIMER_FREQ_64KHZ    = BITFIELD(0, 3, 2),
    TIMER_FREQ_16KHZ    = BITFIELD(0, 3, 3),
    TIMER_FREQ_CASCADE  = BITFIELD(0, 3, 4),
    TIMER_IRQ_ENABLE    = BIT(6),
    TIMER_ENABLE        = BIT(7),
};

extern void timerSet(u32 num, u16 reload, u16 flags);

extern void timerEnable(u32 num);

extern void timerDisable(u32 num);

extern u16 timerGetValue(u32 num);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_TIMER_H */
