/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SVC_SYSTEM_H
#define _LIBSEVEN_SVC_SYSTEM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

enum BiosChecksum
{
    BIOS_CHECKSUM_GBA = 0xBAAE187F,
    BIOS_CHECKSUM_NDS = 0xBAAE1880,
};

extern u32 svcBiosChecksum(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_SYSTEM_H */

