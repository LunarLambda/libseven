/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_CPU_H
#define _LIBSEVEN_HW_CPU_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define BF_PSR_MODE_OFFSET 0
#define BF_PSR_MODE_LENGTH 5

#define PSR_MODE(n) BITFIELD(PSR_MODE, (n))

#define BF_PSR_CONTROL_BITS_OFFSET 0
#define BF_PSR_CONTROL_BITS_LENGTH 8

#define PSR_CONTROL_BITS(n) BITFIELD(PSR_CONTROL_BITS, (n))

#define BF_PSR_FLAGS_OFFSET 28
#define BF_PSR_FLAGS_LENGHT 4

#define PSR_FLAGS(n) BITFIELD(PSR_FLAGS, (n))

enum ProgramStatusRegister
{
    PSR_MODE_USR = PSR_MODE(0x10),
    PSR_MODE_FIQ = PSR_MODE(0x11),
    PSR_MODE_IRQ = PSR_MODE(0x12),
    PSR_MODE_SVC = PSR_MODE(0x13),
    PSR_MODE_ABT = PSR_MODE(0x17),
    PSR_MODE_UND = PSR_MODE(0x1B),
    PSR_MODE_SYS = PSR_MODE(0x1F),

    PSR_STATE_THUMB = BIT(5),

    PSR_FIQ_DISABLE = BIT(6),
    PSR_IRQ_DISABLE = BIT(7),

    PSR_FLAG_V = BIT(28),
    PSR_FLAG_C = BIT(29),
    PSR_FLAG_Z = BIT(30),
    PSR_FLAG_N = BIT(31),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_CPU_H */
