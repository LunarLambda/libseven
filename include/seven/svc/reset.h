/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SVC_RESET_H
#define _LIBSEVEN_SVC_RESET_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void NORETURN svcSoftReset(void);
extern void NORETURN svcHardReset(void);

enum SoftResetExFlags
{
    SRE_FROM_ROM = 0,
    SRE_FROM_RAM = 1,
};

// Combines svcRegisterRamReset and svcSoftReset
// Allows reset from EWRAM, automatically unsets RRR_EWRAM
// Disables IME to prevent IRQs crashing from a dangling handler
extern void NORETURN svcSoftResetEx(u8 reset_flags, bool from_ewram);

enum RegisterRamResetFlags
{
    RRR_EWRAM           = BIT(0),
    RRR_IWRAM           = BIT(1),
    RRR_PALETTE         = BIT(2),
    RRR_VRAM            = BIT(3),
    RRR_OAM             = BIT(4),
    RRR_SIO             = BIT(5),
    RRR_SOUND           = BIT(6),
    RRR_REGISTERS       = BIT(7),
    RRR_EVERYTHING      = BITS(8),
};

extern void svcRegisterRamReset(u8 reset_flags);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_RESET_H */
