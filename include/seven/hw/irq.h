/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_IRQ_H
#define _LIBSEVEN_HW_IRQ_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Used with IE, IF and IFBIOS registers, and IntrWait functions.
enum IRQ
{
    IRQ_VBLANK          = BIT(0),
    IRQ_HBLANK          = BIT(1),
    IRQ_VCOUNT          = BIT(2),
    IRQ_TIMER_0         = BIT(3),
    IRQ_TIMER_1         = BIT(4),
    IRQ_TIMER_2         = BIT(5),
    IRQ_TIMER_3         = BIT(6),
    IRQ_SERIAL          = BIT(7),
    IRQ_DMA_0           = BIT(8),
    IRQ_DMA_1           = BIT(9),
    IRQ_DMA_2           = BIT(10),
    IRQ_DMA_3           = BIT(11),
    IRQ_KEYPAD          = BIT(12),
    IRQ_CARTRIDGE       = BIT(13),
};

// TODO: Naming
enum IRQGroup
{
    // Video blanking IRQs.
    IRQS_BLANK          = IRQ_VBLANK  | IRQ_HBLANK,

    // Timers.
    IRQS_TIMER          = IRQ_TIMER_0 | IRQ_TIMER_1 | IRQ_TIMER_2 | IRQ_TIMER_3,

    // DMA.
    IRQS_DMA            = IRQ_DMA_0   | IRQ_DMA_1   | IRQ_DMA_2   | IRQ_DMA_3,

    // IRQs triggered by external hardware events.
    // IRQs in this group can wake up the GBA from a svcStop() call.
    IRQS_EXTERNAL       = IRQ_SERIAL  | IRQ_KEYPAD  | IRQ_CARTRIDGE,

    IRQS_ALL            = BITS(0, 13),
};

enum IRQIndex
{
    IRQINDEX_VBLANK,
    IRQINDEX_HBLANK,
    IRQINDEX_VCOUNT,
    IRQINDEX_TIMER_0,
    IRQINDEX_TIMER_1,
    IRQINDEX_TIMER_2,
    IRQINDEX_TIMER_3,
    IRQINDEX_SERIAL,
    IRQINDEX_DMA_0,
    IRQINDEX_DMA_1,
    IRQINDEX_DMA_2,
    IRQINDEX_DMA_3,
    IRQINDEX_KEYPAD,
    IRQINDEX_CARTRIDGE,
    IRQINDEX_MAX,
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

#define IRQ_HANDLER (*(IRQHandler **volatile)0x03FFFFFC)

extern bool irqMasterEnable(void);
extern bool irqMasterDisable(void);
extern bool irqMasterSetEnabled(bool enable);

extern void irqInit(IRQHandler *isr);

extern void irqInitDefault(void);

extern u16 irqEnable(u16 intr_flags);
extern u16 irqDisable(u16 intr_flags);
extern u16 irqSetEnabled(u16 intr_flags);

// Saves the current value of IME and disables IME.
// Nested calls are possible, only the outermost call has any effect.
extern void irqCriticalSectionEnter(void);
// Restores the value in IME saved by a previous call to EnterCriticalSection.
extern void irqCriticalSectionExit(void);

// Returns true if inside a critical section
extern bool irqCriticalSectionActive(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_IRQ_H */
