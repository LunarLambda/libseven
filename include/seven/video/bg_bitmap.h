/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_BITMAP_H
#define _LIBSEVEN_VIDEO_BG_BITMAP_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define MODE3_WIDTH  240
#define MODE3_HEIGHT 160

typedef       u16 Mode3Line[MODE3_WIDTH];
typedef Mode3Line Mode3Frame[MODE3_HEIGHT];

#define MODE3_FRAME     MEMADDR(MEM_VRAM, Mode3Frame)

extern void* lcdInitMode3(void);

#define MODE4_WIDTH  240
#define MODE4_HEIGHT 160

typedef       u16 Mode4Line[MODE4_WIDTH/2];
typedef Mode4Line Mode4Frame[MODE4_HEIGHT];

#define MODE4_FRAME     MEMADDR(MEM_VRAM, Mode4Frame)
#define MODE4_FRAME2    MEMADDR(MEM_VRAM + 0xA000, Mode4Frame)

#define M4PX(l, h) ((u16)((l) << 8 | (u8)(h)))

extern void* lcdInitMode4(void);

#define MODE5_WIDTH  160
#define MODE5_HEIGHT 128

typedef       u16 Mode5Line[MODE5_WIDTH];
typedef Mode5Line Mode5Frame[MODE5_HEIGHT];

#define MODE5_FRAME     MEMADDR(MEM_VRAM, Mode5Frame)
#define MODE5_FRAME2    MEMADDR(MEM_VRAM + 0xA000, Mode5Frame)

extern void* lcdInitMode5(void);

extern void* lcdSwapBuffers(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_BITMAP_H */
