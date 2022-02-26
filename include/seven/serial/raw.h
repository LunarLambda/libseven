/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SERIAL_RAW_H
#define _LIBSEVEN_SERIAL_RAW_H

#error "seven/serial/raw.h is unfinished and should not be used"

#include <seven/base.h>
#include <seven/hw/serial.h>

_LIBSEVEN_EXTERN_C

// "Raw mode" access register
#define REG_SIORAW       VOLADDR(0x04000134, u16)

enum SerialIORaw
{
    SIO_RAW_SC_DATA       = BIT(0),
    SIO_RAW_SD_DATA       = BIT(1),
    SIO_RAW_SI_DATA       = BIT(2),
    SIO_RAW_SO_DATA       = BIT(3),

    SIO_RAW_SC_DIR_OUT    = BIT(4),
    SIO_RAW_SC_DIR_IN     = !SIO_RAW_SC_DIR_OUT,

    SIO_RAW_SD_DIR_OUT    = BIT(5),
    SIO_RAW_SD_DIR_IN     = !SIO_RAW_SD_DIR_OUT,

    SIO_RAW_SI_DIR_OUT    = BIT(6),
    SIO_RAW_SI_DIR_IN     = !SIO_RAW_SI_DIR_OUT,

    SIO_RAW_SO_DIR_OUT    = BIT(7),
    SIO_RAW_SO_DIR_IN     = !SIO_RAW_SO_DIR_OUT,

    SIO_RAW_SI_IRQ_ENABLE = BIT(8),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SERIAL_RAW_H */
