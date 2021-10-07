#ifndef _LIBSEVEN_MEMORY_H
#define _LIBSEVEN_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <seven/base.h>

// BIOS ROM (16K)
#define MEM_BIOS                ((const void*)0x00000000)
#define MEM_BIOS_SIZE           ((size_t)0x4000)

// External Work RAM (256K)
#define MEM_EWRAM               ((void*)0x02000000)
#define MEM_EWRAM_SIZE          ((size_t)0x40000)

// Internal Work RAM (32K)
#define MEM_IWRAM               ((void*)0x03000000)
#define MEM_IWRAM_SIZE          ((size_t)0x8000)

// I/O Register Area
#define MEM_IO                  ((volatile void*)0x04000000)
// If you include undocumented registers, it's 0x804.
#define MEM_IO_SIZE             ((size_t)0x300)

// Video Palette (1K)
#define MEM_PALETTE             ((void*)0x05000000)
#define MEM_PALETTE_SIZE        ((size_t)0x400)

// Video RAM (96K)
#define MEM_VRAM                ((void*)0x06000000)
#define MEM_VRAM_SIZE           ((size_t)0x18000)

// Object Attribute Memory (1K)
#define MEM_OAM                 ((void*)0x07000000)
#define MEM_OAM_SIZE            ((size_t)0x400)

// Cartridge ROM (32M)
#define MEM_ROM                 ((const void*)0x08000000)
#define MEM_ROM_SIZE            ((size_t)0x02000000)

// Cartridge Static RAM (64K)
#define MEM_SRAM                ((void*)0x0E000000)
#define MEM_SRAM_SIZE           ((size_t)0x10000)

enum WaitstateFlags
{
    WS_SRAM_WAIT_4              = BITFIELD(0, 2, 0),
    WS_SRAM_WAIT_3              = BITFIELD(0, 2, 1),
    WS_SRAM_WAIT_2              = BITFIELD(0, 2, 2),
    WS_SRAM_WAIT_8              = BITFIELD(0, 2, 3),

    WS_ROM_N_WAIT_4             = BITFIELD(2, 2, 0),
    WS_ROM_N_WAIT_3             = BITFIELD(2, 2, 1),
    WS_ROM_N_WAIT_2             = BITFIELD(2, 2, 2),
    WS_ROM_N_WAIT_8             = BITFIELD(2, 2, 3),

    WS_ROM_S_WAIT_2             = BITFIELD(4, 1, 0),
    WS_ROM_S_WAIT_1             = BITFIELD(4, 1, 1),

    WS_PHI_OFF                  = BITFIELD(11, 2, 0),
    WS_PHI_4MHZ                 = BITFIELD(11, 2, 1),
    WS_PHI_8MHZ                 = BITFIELD(11, 2, 2),
    WS_PHI_16MHZ                = BITFIELD(12, 2, 3),

    WS_CARTRIDGE_PREFETCH       = BIT(14),
    WS_CARTRIDGE_TYPE_CGB       = BIT(15),
    WS_CARTRIDGE_TYPE_GBA       = !WS_CARTRIDGE_TYPE_CGB,
};

#define REG_WSCNT       REG16(0x04000204)

enum CpuSetFlags
{
    CS_SRC_FIXED        = BIT(24),
    CS_32BIT            = BIT(26),
    CS_16BIT            = !CS_32BIT,
};

extern void svcCpuSet(const void *src, void *dst, u32 ctrl);
extern void svcCpuSetFixed(u32 value, void *dst, u32 ctrl);

enum CpuFastSetFlags
{
    CFS_SRC_FIXED       = BIT(24),
};

extern void svcCpuFastSet(const void *src, void *dst, u32 ctrl);
extern void svcCpuFastSetFixed(u32 value, void *dst, u32 ctrl);

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_MEMORY_H */
