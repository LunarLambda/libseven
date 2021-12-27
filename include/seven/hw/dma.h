#ifndef _LIBSEVEN_HW_DMA_H
#define _LIBSEVEN_HW_DMA_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// RAM Only
#define DMA_INTERNAL_MEMORY     0x07FFFFFF
// Except SRAM due to 8-bit only bus
#define DMA_ALL_MEMORY          0x0FFFFFFF

#define REG_DMA0SRC     REG32(0x040000B0)
#define REG_DMA0DST     REG32(0x040000B4)
#define REG_DMA0LEN     REG16(0x040000B8)
#define REG_DMA0CNT     REG16(0x040000BA)

#define DMA0SRC_MAX     DMA_INTERNAL_MEMORY
#define DMA0DST_MAX     DMA_INTERNAL_MEMORY
#define DMA0LEN_MAX     0x4000

#define REG_DMA1SRC     REG32(0x040000BC)
#define REG_DMA1DST     REG32(0x040000C0)
#define REG_DMA1LEN     REG16(0x040000C4)
#define REG_DMA1CNT     REG16(0x040000C6)

#define DMA1SRC_MAX     DMA_ALL_MEMORY
#define DMA1DST_MAX     DMA_INTERNAL_MEMORY
#define DMA1LEN_MAX     0x4000

#define REG_DMA2SRC     REG32(0x040000C8)
#define REG_DMA2DST     REG32(0x040000CC)
#define REG_DMA2LEN     REG16(0x040000D0)
#define REG_DMA2CNT     REG16(0x040000D2)

#define DMA2SRC_MAX     DMA_ALL_MEMORY
#define DMA2DST_MAX     DMA_INTERNAL_MEMORY
#define DMA2LEN_MAX     0x4000

#define REG_DMA3SRC     REG32(0x040000D4)
#define REG_DMA3DST     REG32(0x040000D8)
#define REG_DMA3LEN     REG16(0x040000DC)
#define REG_DMA3CNT     REG16(0x040000DE)

#define DMA3SRC_MAX     DMA_ALL_MEMORY
#define DMA3DST_MAX     DMA_ALL_MEMORY
#define DMA3LEN_MAX     0x10000

enum DMAControl
{
    DMA_DST_INCREMENT   = BITFIELD(5, 2, 0),
    DMA_DST_DECREMENT   = BITFIELD(5, 2, 1),
    DMA_DST_FIXED       = BITFIELD(5, 2, 2),
    DNA_DST_REPEAT      = BITFIELD(5, 2, 3),

    DMA_SRC_INCREMENT   = BITFIELD(7, 2, 0),
    DMA_SRC_DECREMENT   = BITFIELD(7, 2, 1),
    DMA_SRC_FIXED       = BITFIELD(7, 2, 2),

    DMA_REPEAT          = BIT(9),

    DMA_32BIT           = BIT(10),
    DMA_16BIT           = !DMA_32BIT,

    DMA_CARTRIDGE_DRQ   = BIT(11),

    DMA_START_NOW       = BITFIELD(12, 2, 0),
    DMA_START_HBLANK    = BITFIELD(12, 2, 1),
    DMA_START_VBLANK    = BITFIELD(12, 2, 2),
    // Forbidden on DMA0
    DMA_START_SPECIAL   = BITFIELD(12, 2, 3),
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
extern void dmaSet(u32 num, const void *src, void *dst, u32 len, u16 flags);

_LIBSEVEN_EXTERN_C_END

#endif /* _LIBSEVEN_HW_DMA_H */