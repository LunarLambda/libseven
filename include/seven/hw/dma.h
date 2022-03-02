/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_DMA_H
#define _LIBSEVEN_HW_DMA_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

//        RAM  ROM  Transfer limit
// DMA 0  R/W   -   16K
// DMA 1  R/W   R   16K
// DMA 2  R/W   R   16K
// DMA 3  R/W  R/W  64K

#define REG_DMA0SRC     VOLADDR(0x040000B0, const void *)
#define REG_DMA0DST     VOLADDR(0x040000B4, void *)
#define REG_DMA0LEN     VOLADDR(0x040000B8, u16)
#define REG_DMA0CNT     VOLADDR(0x040000BA, u16)

#define REG_DMA1SRC     VOLADDR(0x040000BC, const void *)
#define REG_DMA1DST     VOLADDR(0x040000C0, void *)
#define REG_DMA1LEN     VOLADDR(0x040000C4, u16)
#define REG_DMA1CNT     VOLADDR(0x040000C6, u16)

#define REG_DMA2SRC     VOLADDR(0x040000C8, const void *)
#define REG_DMA2DST     VOLADDR(0x040000CC, void *)
#define REG_DMA2LEN     VOLADDR(0x040000D0, u16)
#define REG_DMA2CNT     VOLADDR(0x040000D2, u16)

#define REG_DMA3SRC     VOLADDR(0x040000D4, const void *)
#define REG_DMA3DST     VOLADDR(0x040000D8, void *)
#define REG_DMA3LEN     VOLADDR(0x040000DC, u16)
#define REG_DMA3CNT     VOLADDR(0x040000DE, u16)

#define BF_DMA_DST_OFFSET 5
#define BF_DMA_DST_LENGTH 2

#define DMA_DST(n) BITFIELD(DMA_DST, (n))

#define BF_DMA_SRC_OFFSET 7
#define BF_DMA_SRC_LENGTH 2

#define DMA_SRC(n) BITFIELD(DMA_SRC, (n))

#define BF_DMA_START_OFFSET 12
#define BF_DMA_START_LENGTH 2

#define DMA_START(n) BITFIELD(DMA_START, (n))

enum DMAControl
{
    DMA_DST_INCREMENT   = DMA_DST(0),
    DMA_DST_DECREMENT   = DMA_DST(1),
    DMA_DST_FIXED       = DMA_DST(2),
    DNA_DST_RELOAD      = DMA_DST(3),

    DMA_SRC_INCREMENT   = DMA_SRC(0),
    DMA_SRC_DECREMENT   = DMA_SRC(1),
    DMA_SRC_FIXED       = DMA_SRC(2),

    DMA_REPEAT          = BIT(9),

    DMA_32BIT           = BIT(10),
    DMA_16BIT           = !DMA_32BIT,

    DMA_START_NOW       = DMA_START(0),
    DMA_START_HBLANK    = DMA_START(1),
    DMA_START_VBLANK    = DMA_START(2),
    DMA_START_SPECIAL   = DMA_START(3),

    // DMA1, DMA2
    DMA_START_SOUND     = DMA_START_SPECIAL,
    // DMA3
    DMA_START_CAPTURE   = DMA_START_SPECIAL,

    // On transfer completion
    DMA_IRQ_ENABLE      = BIT(14),
    DMA_ENABLE          = BIT(15),
};

extern void dmaEnable(u32 num);
extern void dmaDisable(u32 num);

// General purpose memory copy using DMA3
extern void dmaCopy16(const void *src, void *dst, u32 len);
extern void dmaCopy32(const void *src, void *dst, u32 len);

// Repeating Sound FIFO A transfer using DMA1
extern void dmaSoundFifoATransfer(const void *src, u16 flags);

// Repeating Sound FIFO B transfer using DMA2
extern void dmaSoundFifoBTransfer(const void *src, u16 flags);

// Repeating H-Blank transfer using DMA0.
extern void dmaHBlankTransfer(const void *src, void *dst, u32 len, u16 flags);

// Atomically sets up a DMA channel, using a byte count
extern void dmaAtomicSet(u32 num, const void *src, void *dst, u32 len, u16 flags);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_DMA_H */
