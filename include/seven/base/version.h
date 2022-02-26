/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_VERSION_H
#define _LIBSEVEN_BASE_VERSION_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define LIBSEVEN_VERSION_MAJOR 0
#define LIBSEVEN_VERSION_MINOR 2
#define LIBSEVEN_VERSION_PATCH 2

#define LIBSEVEN_VERSION \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_MAJOR) "." \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_MINOR) "." \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_PATCH)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_VERSION_H */

