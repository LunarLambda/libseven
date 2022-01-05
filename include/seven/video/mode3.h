/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_MODE3_H
#define _LIBSEVEN_VIDEO_MODE3_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define MODE3_WIDTH  240
#define MODE3_HEIGHT 160

typedef       u16 Mode3Line[MODE3_WIDTH];
typedef Mode3Line Mode3Frame[MODE3_HEIGHT];

#define MODE3_FRAME     MEMDEFW(Mode3Frame, MEM_VRAM)

extern void* lcdInitMode3(void);

_LIBSEVEN_EXTERN_C_END

#endif
