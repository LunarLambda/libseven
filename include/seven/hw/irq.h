/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_IRQ_H
#define _LIBSEVEN_HW_IRQ_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Attribute for compiling functions in a way that is suitable for IRQ handlers.
//
#define IRQ_HANDLER     IWRAM_CODE ARM_CODE

// Interrupt Enable
//
#define REG_IE          REG16(0x04000200)

// Interrupt Flags
//
#define REG_IF          REG16(0x04000202)

// Interrupt Master Enable
//
#define REG_IME         REG16(0x04000208)

// IRQ bitflags
//
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

// Common sets of IRQs
//
enum IRQGroup
{
    IRQS_BLANK          = IRQ_VBLANK  | IRQ_HBLANK,
    IRQS_TIMER          = IRQ_TIMER_0 | IRQ_TIMER_1 | IRQ_TIMER_2 | IRQ_TIMER_3,
    IRQS_DMA            = IRQ_DMA_0   | IRQ_DMA_1   | IRQ_DMA_2   | IRQ_DMA_3,
    // IRQs in this group can wake up the GBA from a svcStop() call.
    IRQS_EXTERNAL       = IRQ_SERIAL  | IRQ_KEYPAD  | IRQ_CARTRIDGE,
    IRQS_ALL            = BITS(14),
};

// Bit indices of IRQs
enum IRQIndex
{
    IRQ_INDEX_VBLANK,
    IRQ_INDEX_HBLANK,
    IRQ_INDEX_VCOUNT,
    IRQ_INDEX_TIMER_0,
    IRQ_INDEX_TIMER_1,
    IRQ_INDEX_TIMER_2,
    IRQ_INDEX_TIMER_3,
    IRQ_INDEX_SERIAL,
    IRQ_INDEX_DMA_0,
    IRQ_INDEX_DMA_1,
    IRQ_INDEX_DMA_2,
    IRQ_INDEX_DMA_3,
    IRQ_INDEX_KEYPAD,
    IRQ_INDEX_CARTRIDGE,
    IRQ_INDEX_MAX,
};

// Function type for interrupt service routines (ISRs)
//
// Function must be ARM code, and ideally be placed in IWRAM.
//
// Use the IRQ_HANDLER attribute to mark the function appropriately.
typedef void IrqHandlerFn(void);

// Function type for interrupt callbacks.
//
// The function receives the triggered IRQs as the first parameter.
typedef void IrqCallbackFn(u16);

// Initialize interrupt handling with a user-provided function.
//
extern void irqInit(IrqHandlerFn *isr);

// Initialize interrupt handling using a callback system.
//
extern void irqInitDefault(void);

// Initialize interrupt handling using a single callback function.
//
// irqInitSimple(my_callback) is roughly similar to
// irqCallbackSet(IRQS_ALL, my_callback, 0),
// but has a lower overhead.
//
extern void irqInitSimple(IrqCallbackFn *fn);

// Initialize interrupt handling using a stub handler
// that only acknowledges the IRQs and returns.
//
// This is enough for svcHalt, svcIntrWait, and svcVBlankIntrWait to work.
//
extern void irqInitStub(void);

// Set the callback associated with the specified irqs.
//
// The priority argument is used to set the search order.
// A lower value specifies a higher priority.
//
// Fails if any of the irqs already have a callback set.
//
extern bool irqCallbackSet(u16 irqs, IrqCallbackFn *fn, u16 priority);

// Delete the callback associated with the specified irqs.
//
// Fails if the irqs don't share a slot, or any of the irqs don't have a slot.
//
extern bool irqCallbackDelete(u16 irqs);

// Gets the highest priority callback function matching the specified irqs,
// or NULL if none is found.
//
// This function is placed in IWRAM so that it can be called quickly from
// a user-provided IRQ handler.
extern IrqCallbackFn* irqCallbackLookup(u16 irqs);

// Enable the specified IRQs.
//
// Returns the old value of the IE register.
//
extern u16 irqEnable(u16 irqs);

// Disable the specified IRQs.
//
// Returns the old value of the IE register.
//
extern u16 irqDisable(u16 irqs);

// Enable the specified IRQs and set the matching I/O registers.
//
// Returns the old value of the IE register.
//
extern u16 irqEnableFull(u16 irqs);

// Disable the specified IRQs and set the matching I/O registers.
//
// Returns the old value of the IE register.
//
extern u16 irqDisableFull(u16 irqs);

// Saves the current value of the IME register and disables it until
// a call to irqCriticalSectionExit.
//
// Calls can be nested. Only the outermost call affects IME.
//
extern void irqCriticalSectionEnter(void);

// Restores the value of IME saved by a
// previous call to irqCriticalSectionEnter.
//
// Only the outermost call affects IME.
//
extern void irqCriticalSectionExit(void);

// Returns true if currently inside a critical section.
//
extern bool irqCriticalSectionActive(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_IRQ_H */
