/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_BITMAP_H
#define _LIBSEVEN_VIDEO_BG_BITMAP_H

#include <seven/base.h>
#include <seven/hw/video.h>
#include <seven/video/bg_transform.h>

_LIBSEVEN_EXTERN_C

#define MODE3_WIDTH  240
#define MODE3_HEIGHT 160
#define MODE3_FRAME  MEMADDR(MEM_VRAM, Mode3Frame)

#define MODE4_WIDTH  240
#define MODE4_HEIGHT 160
#define MODE4_FRAME_0  MEMADDR(MEM_VRAM, Mode4Frame)
#define MODE4_FRAME_1 MEMADDR(MEM_VRAM + 0xA000, Mode4Frame)

#define M4PX(l, h) ((u16)((l) << 8 | (u8)(h)))

#define MODE5_WIDTH  160
#define MODE5_HEIGHT 128
#define MODE5_FRAME_0  MEMADDR(MEM_VRAM, Mode5Frame)
#define MODE5_FRAME_1 MEMADDR(MEM_VRAM + 0xA000, Mode5Frame)

typedef u16 Mode3Frame[MODE3_HEIGHT][MODE3_WIDTH];
typedef u16 Mode4Frame[MODE4_HEIGHT][MODE4_WIDTH/2];
typedef u16 Mode5Frame[MODE5_HEIGHT][MODE5_HEIGHT];

extern void* bmpInitMode3(void);
extern void* bmpInitMode4(void);
extern void* bmpInitMode5(void);
extern void* bmpSwapBuffers(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_BITMAP_H */
