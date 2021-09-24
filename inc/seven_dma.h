#ifndef _LIBSEVEN_DMA_H
#define _LIBSEVEN_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

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
#define DMA0LEN_MAX     0x3FFF

#define REG_DMA1SRC     REG32(0x040000BC)
#define REG_DMA1DST     REG32(0x040000C0)
#define REG_DMA1LEN     REG16(0x040000C4)
#define REG_DMA1CNT     REG16(0x040000C6)

#define DMA1SRC_MAX     DMA_ALL_MEMORY
#define DMA1DST_MAX     DMA_INTERNAL_MEMORY
#define DMA1LEN_MAX     0x3FFF

#define REG_DMA2SRC     REG32(0x040000C8)
#define REG_DMA2DST     REG32(0x040000CC)
#define REG_DMA2LEN     REG16(0x040000D0)
#define REG_DMA2CNT     REG16(0x040000D2)

#define DMA2SRC_MAX     DMA_ALL_MEMORY
#define DMA2DST_MAX     DMA_INTERNAL_MEMORY
#define DMA2LEN_MAX     0x3FFF

#define REG_DMA3SRC     REG32(0x040000D4)
#define REG_DMA3DST     REG32(0x040000D8)
#define REG_DMA3LEN     REG16(0x040000DC)
#define REG_DMA3CNT     REG16(0x040000DE)

#define DMA3SRC_MAX     DMA_ALL_MEMORY
#define DMA3DST_MAX     DMA_ALL_MEMORY
#define DMA3LEN_MAX     0xFFFF

#define DMACNT(n)       REG16_ARRAY_STRIDE(0x040000BA, 12, n)

enum DMAFlags
{
    DMA_DST_INCREMENT   = BITFIELD(5, 0),
    DMA_DST_DECREMENT   = BITFIELD(5, 1),
    DMA_DST_FIXED       = BITFIELD(5, 2),
    DNA_DST_REPEAT      = BITFIELD(5, 3),

    DMA_SRC_INCREMENT   = BITFIELD(7, 0),
    DMA_SRC_DECREMENT   = BITFIELD(7, 1),
    DMA_SRC_FIXED       = BITFIELD(7, 2),

    DMA_REPEAT          = BIT(9),

    DMA_32BIT           = BIT(10),
    DMA_16BIT           = !DMA_32BIT,

    // What's this? DMA3 only.
    DMA_CARTRIDGE_DRQ   = BIT(11),

    DMA_START_NOW       = BITFIELD(12, 0),
    DMA_START_HBLANK    = BITFIELD(12, 1),
    DMA_START_VBLANK    = BITFIELD(12, 2),

    // Forbidden on DMA0
    DMA_START_SPECIAL   = BITFIELD(12, 3),
    // DMA1, DMA2
    DMA_START_SOUND     = DMA_START_SPECIAL,
    // DMA3
    DMA_START_CAPTURE   = DMA_START_SPECIAL,

    // On transfer completion
    DMA_IRQ_ENABLE      = BIT(14),
    DMA_ENABLE          = BIT(15),
};

static inline void dmaEnable(u32 num)
{
    if (num > 3)
    {
        return;
    }

    DMACNT(num) |= DMA_ENABLE;
}

static inline void dmaDisable(u32 num)
{
    if (num > 3)
    {
        return;
    }

    DMACNT(num) &= ~DMA_ENABLE;
}

// General purpose memory copy using DMA3.
extern void dmaTransfer(const void *src, void *dst, u16 count, u16 flags);

// Sets up an HDMA transfer on DMA0.
extern void dmaHBlankTransfer(const void *src, void *dst, u16 count, u16 flags);

#ifdef __cplusplus
}
#endif

#endif /* _LIBSEVEN_DMA_H */
