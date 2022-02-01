/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_UTIL_PROFILE_H
#define _LIBSEVEN_UTIL_PROFILE_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Measures how many CPU cycles it takes to execute the given function,
// using timers 2 and 3.
//
// If the function returns a value in r0, and return_value is not NULL,
// the value will be stored in return_value.
extern u32 profileRun(u32 (*function)(void), u32 *return_value);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_PROFILE_H */
