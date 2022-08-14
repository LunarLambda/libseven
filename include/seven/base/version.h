/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_VERSION_H
#define _LIBSEVEN_BASE_VERSION_H

#include <seven/base.h>

#define LIBSEVEN_VERSION_MAJOR 0
#define LIBSEVEN_VERSION_MINOR 3
#define LIBSEVEN_VERSION_PATCH 9

#define LIBSEVEN_VERSION \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_MAJOR) "." \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_MINOR) "." \
    _LIBSEVEN_STR2(LIBSEVEN_VERSION_PATCH)

#endif /* !_LIBSEVEN_BASE_VERSION_H */

