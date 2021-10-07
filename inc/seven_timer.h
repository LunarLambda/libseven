#ifndef _LIBSEVEN_TIMER_H
#define _LIBSEVEN_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <seven_base.h>

#define REG_TM0VAL      REG16(0x04000100)
#define REG_TM0CNT      REG16(0x04000102)

#define REG_TM1VAL      REG16(0x04000104)
#define REG_TM1CNT      REG16(0x04000106)

#define REG_TM2VAL      REG16(0x04000108)
#define REG_TM2CNT      REG16(0x0400010A)

#define REG_TM3VAL      REG16(0x0400010C)
#define REG_TM3CNT      REG16(0x0400010E)

enum TimerFlags
{
    TIMER_FREQ_16MHZ    = BITFIELD(0, 2, 0),
    TIMER_FREQ_262KHZ   = BITFIELD(0, 2, 1),
    TIMER_FREQ_64KHZ    = BITFIELD(0, 2, 2),
    TIMER_FREQ_16KHZ    = BITFIELD(0, 2, 3),
    TIMER_CASCADE       = BIT(2),
    TIMER_IRQ_ENABLE    = BIT(6),
    TIMER_ENABLE        = BIT(7),
};

extern void timerSet(u32 num, u16 reload, u16 flags);

extern void timerStart(u32 num);

extern void timerStop(u32 num);

extern u16 timerGetValue(u32 num);

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_TIMER_H */
