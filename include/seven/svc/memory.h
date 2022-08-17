/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SVC_MEMORY_H
#define _LIBSEVEN_SVC_MEMORY_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

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

#endif /* !_LIBSEVEN_SVC_MEMORY_H */
