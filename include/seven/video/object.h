/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_OBJECT_H
#define _LIBSEVEN_VIDEO_OBJECT_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

struct Object
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
} ALIGN(8);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_OBJECT_H */
