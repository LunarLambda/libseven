#ifndef _LIBSEVEN_HW_IRQ_H
#define _LIBSEVEN_HW_IRQ_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// IRQ Flags. Used with IE, IF and IFBIOS registers, and IntrWait functions.
enum IRQFlags
{
    IRQ_VBLANK          = BIT(0),
    IRQ_HBLANK          = BIT(1),
    IRQ_VCOUNT          = BIT(2),
    IRQ_TIMER_0         = BIT(3),
    IRQ_TIMER_1         = BIT(4),
    IRQ_TIMER_2         = BIT(5),
    IRQ_TIMER_3         = BIT(6),
    IRQ_SIO             = BIT(7),
    IRQ_DMA_0           = BIT(8),
    IRQ_DMA_1           = BIT(9),
    IRQ_DMA_2           = BIT(10),
    IRQ_DMA_3           = BIT(11),
    IRQ_KEYPAD          = BIT(12),
    IRQ_CARTRIDGE       = BIT(13),
};

// Interrupt Enable
#define REG_IE          REG16(0x04000200)

// Interrupt Flags
#define REG_IF          REG16(0x04000202)

// Interrupt Master Enable
#define REG_IME         REG16(0x04000208)

// Interrupt Flags (for BIOS IntrWait functions)
#define REG_IFBIOS      REG16(0x03FFFFF8)

typedef void IRQHandler(void);

extern IRQHandler irqDefaultHandler;

#define IRQ_HANDLER (*(IRQHandler **volatile)0x03FFFFFC)

static inline u32 irqSetIME(u32 v)
{
    u32 old = REG_IME;
    REG_IME = v;

    return old;
}

static inline u32 irqEnableIME(void)
{
    return irqSetIME(1);
}

static inline u32 irqDisableIME(void)
{
    return irqSetIME(0);
}

static inline void irqInit(IRQHandler *isr)
{
    REG_IME     = 0;
    REG_IF      = 0xFFFF;
    REG_IE      = 0;

    IRQ_HANDLER = isr ? isr : irqDefaultHandler;

    REG_IME     = 1;
}

extern u16 irqEnable(u16 intr_flags);
extern u16 irqDisable(u16 intr_flags);
extern u16 irqSetEnabled(u16 intr_flags);

// Saves the current value of IME and disables IME.
// Nested calls are possible, only the outermost call has any effect.
extern void irqEnterCriticalSection(void);
// Restores the value in IME saved by a previous call to EnterCriticalSection.
extern void irqExitCriticalSection(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_IRQ_H */
