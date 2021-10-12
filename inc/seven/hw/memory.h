#ifndef _LIBSEVEN_HW_MEMORY_H
#define _LIBSEVEN_HW_MEMORY_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

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

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_MEMORY_H */
