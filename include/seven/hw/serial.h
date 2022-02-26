/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_SERIAL_H
#define _LIBSEVEN_HW_SERIAL_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_SIOCNT    VOLADDR(0x04000128, u16)
#define REG_SIOMODE2  VOLADDR(0x04000134, u16)
#define REG_SIODATA8  VOLADDR(0x0400012A, u8)
#define REG_SIODATA32 VOLADDR(0x04000120, u32)

enum SerialIOControl
{
    SIO_CLOCK_INTERNAL    = BIT(0),
    SIO_CLOCK_EXTERNAL    = !SIO_CLOCK_INTERNAL,

    SIO_CLOCK_FREQ_2MHZ   = BIT(1),
    SIO_CLOCK_FREQ_256KHZ = !SIO_CLOCK_FREQ_2MHZ,

    SIO_SO_READY_HIGH     = BIT(3),
    SIO_SO_READY_LOW      = !SIO_SO_READY_HIGH,

    SIO_START             = BIT(7),

    SIO_32BIT             = BIT(12),
    SIO_8BIT              = !SIO_32BIT,

    #define BF_SIO_MODE_OFFSET 12
    #define BF_SIO_MODE_LENGTH 2

    #define SIO_MODE(n) BITFIELD(SIO_MODE, (n))

    SIO_MODE_NORMAL       = SIO_MODE(0),
    SIO_MODE_MULTI        = SIO_MODE(2),
    SIO_MODE_UART         = SIO_MODE(3),

    // These are for symmetry, raw & JOY Bus modes ignore the SIO_MODE bits.
    SIO_MODE_RAW          = SIO_MODE(0),
    SIO_MODE_JOYBUS       = SIO_MODE(0),

    SIO_IRQ_ENABLE        = BIT(14),
};

enum SerialIOMode2
{
    #define BF_SIO_MODE2_OFFSET 14
    #define BF_SIO_MODE2_LENGTH 2

    #define SIO_MODE2(n) BITFIELD(SIO_MODE2, (n))

    SIO_MODE2_NORMAL     = SIO_MODE2(0),
    SIO_MODE2_MULTI      = SIO_MODE2(0),
    SIO_MODE2_UART       = SIO_MODE2(0),

    SIO_MODE2_RAW        = SIO_MODE2(2),
    SIO_MODE2_JOYBUS     = SIO_MODE2(3),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SERIAL_H */
