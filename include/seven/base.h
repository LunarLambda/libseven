/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_H
#define _LIBSEVEN_BASE_H

#ifdef __cplusplus
#define _LIBSEVEN_EXTERN_C extern "C" {
#define _LIBSEVEN_EXTERN_C_END }
#else
#define _LIBSEVEN_EXTERN_C
#define _LIBSEVEN_EXTERN_C_END
#endif

_LIBSEVEN_EXTERN_C

#include <seven/base/attributes.h>
#include <seven/base/bits.h>
#include <seven/base/registers.h>
#include <seven/base/types.h>

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_H */
