#ifndef _LIBSEVEN_IRQ_H
#define _LIBSEVEN_IRQ_H

#include <seven_base.h>

// IRQ Flags. Used with IE, IF and IFBIOS registers, and IntrWait functions.
enum IRQFlags
{
    IRQ_LCD_VBLANK      = BIT(0),
    IRQ_LCD_HBLANK      = BIT(1),
    IRQ_LCD_VCOUNT      = BIT(2),
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

static inline void irqEnableIME(void)
{
    REG_IME = 1;
}

static inline void irqDisableIME(void)
{
    REG_IME = 0;
}

static inline void irqEnable(u16 flags)
{
    REG_IE |= flags;
}

static inline void irqDisable(u16 flags)
{
    REG_IE &= ~flags;
}

static inline void irqInit(IRQHandler *isr)
{
    irqEnableIME();
    IRQ_HANDLER = isr ? isr : irqDefaultHandler;
}

#endif /* !_LIBSEVEN_IRQ_H */
