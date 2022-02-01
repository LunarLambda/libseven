/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_WAITSTATE_H
#define _LIBSEVEN_HW_WAITSTATE_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_WAITCNT             REG16(0x04000204)

#define BF_WAIT_SRAM_OFFSET     0
#define BF_WAIT_SRAM_LENGTH     2

#define BF_WAIT_ROM_N_OFFSET    2
#define BF_WAIT_ROM_N_LENGTH    2

#define BF_WAIT_ROM_S_OFFSET    4
#define BF_WAIT_ROM_S_LENGTH    1

enum Waitstate
{
    WAIT_SRAM_4          = BITFIELD(WAIT_SRAM, 0),
    WAIT_SRAM_3          = BITFIELD(WAIT_SRAM, 1),
    WAIT_SRAM_2          = BITFIELD(WAIT_SRAM, 2),
    WAIT_SRAM_8          = BITFIELD(WAIT_SRAM, 3),

    WAIT_ROM_N_4         = BITFIELD(WAIT_ROM_N, 0),
    WAIT_ROM_N_3         = BITFIELD(WAIT_ROM_N, 1),
    WAIT_ROM_N_2         = BITFIELD(WAIT_ROM_N, 2),
    WAIT_ROM_N_8         = BITFIELD(WAIT_ROM_N, 3),

    WAIT_ROM_S_2         = BITFIELD(WAIT_ROM_S, 0),
    WAIT_ROM_S_1         = BITFIELD(WAIT_ROM_S, 1),

    WAIT_PREFETCH_ENABLE = BIT(14),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_WAITSTATE_H */