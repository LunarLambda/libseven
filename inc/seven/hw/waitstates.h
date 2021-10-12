#ifndef _LIBSEVEN_HW_WAITSTATES_H
#define _LIBSEVEN_HW_WAITSTATES_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

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

    WS_CART_PREFETCH_ENABLE     = BIT(14),
    WS_CART_TYPE_CGB            = BIT(15),
    WS_CART_TYPE_GBA            = !WS_CARTRIDGE_TYPE_CGB,
};

#define REG_WSCNT               REG16(0x04000204)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_WAITSTATES_H */
