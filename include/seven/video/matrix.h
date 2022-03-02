/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_MATRIX_H
#define _LIBSEVEN_VIDEO_MATRIX_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

struct Matrix
{
    i16 hdx;
    i16 vdx;
    i16 hdy;
    i16 vdy;
} ALIGN(4);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_MATRIX_H */
