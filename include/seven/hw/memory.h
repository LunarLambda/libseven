/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_MEMORY_H
#define _LIBSEVEN_HW_MEMORY_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// BIOS ROM (16K)
#define MEM_BIOS                ((const void*)0x00000000)
#define MEM_BIOS_SIZE           ((usize)0x4000)

// External Work RAM (256K)
#define MEM_EWRAM               ((void*)0x02000000)
#define MEM_EWRAM_SIZE          ((usize)0x40000)

// Internal Work RAM (32K)
#define MEM_IWRAM               ((void*)0x03000000)
#define MEM_IWRAM_SIZE          ((usize)0x8000)

// I/O Register Area
#define REG_BASE                ((volatile void*)0x04000000)
#define MEM_IO                  ((volatile void*)0x04000000)
// If you include undocumented registers, it's 0x804.
#define MEM_IO_SIZE             ((usize)0x20C)

// Video Palette (1K)
#define MEM_PALETTE             ((void*)0x05000000)
#define MEM_PALETTE_SIZE        ((usize)0x400)

// Video RAM (96K)
#define MEM_VRAM                ((void*)0x06000000)
#define MEM_VRAM_SIZE           ((usize)0x18000)

// Object Attribute Memory (1K)
#define MEM_OAM                 ((void*)0x07000000)
#define MEM_OAM_SIZE            ((usize)0x400)

// Cartridge ROM (32M)
#define MEM_ROM                 ((const void*)0x08000000)
#define MEM_ROM_SIZE            ((usize)0x02000000)

// Cartridge Static RAM (32K)
#define MEM_SRAM                ((void*)0x0E000000)
#define MEM_SRAM_SIZE           ((usize)0x8000)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_MEMORY_H */
