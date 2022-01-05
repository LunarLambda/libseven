/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_UTIL_RANDOM_H
#define _LIBSEVEN_UTIL_RANDOM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void randSetSeed(u32 seed);

extern u32 randNext(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_RANDOM_H */
