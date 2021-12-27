#ifndef _LIBSEVEN_SVC_SYSTEM_H
#define _LIBSEVEN_SVC_SYSTEM_H

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
    RRR_EVERYTHING      = BITS(0, 8),
};

extern void svcRegisterRamReset(u8 reset_flags);

extern void svcHalt(void);
extern void svcStop(void);

extern u32 svcBiosChecksum(void);
extern bool svcIsSystemDS(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_SYSTEM_H */
