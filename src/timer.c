#include <seven_base.h>
#include <seven_timer.h>
#include <seven_irq.h>

// TODO: Consider adding these into timer.h
// Maybe integrate macros like this into registers.h
//
// #define REG_TM REG32_ARRAY(0x04000100)
// => (&REG32(0x04000100))
//
// #define REG_TMRLD(num) REG16_ARRAY_STRIDE(0x04000100, 4, num)
// => REG16((addr) + (stride) * (num))
//
#define REG_TM ((reg32*)0x04000100)
#define REG_TMVAL(num) (*(reg16*)(&REG_TM0VAL + (num) * 4))
#define REG_TMCNT(num) (*(reg16*)(&REG_TM0CNT + (num) * 4))

extern void timerSet(u32 num, u16 reload, u16 flags)
{
    if (num > 3)
    {
        return;
    }

    if (flags & TIMER_IRQ_ENABLE)
    {
        REG_IE |= (IRQ_TIMER_0 << num);
    }

    REG_TM[num] = reload | (flags << 16);
}

extern void timerStart(u32 num)
{
    if (num > 3)
    {
        return;
    }

    REG_TMCNT(num) |= TIMER_ENABLE;
}

extern void timerStop(u32 num)
{
    if (num > 3)
    {
        return;
    }

    REG_TMCNT(num) &= ~TIMER_ENABLE;
}

extern u16 timerGetValue(u32 num)
{
    if (num > 3)
    {
        return 0;
    }

    return REG_TMVAL(num);
}
