/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_SCROLL_H
#define _LIBSEVEN_VIDEO_BG_SCROLL_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

#define REG_BG0HOFS     VOLADDR(0x04000010, u16)
#define REG_BG0VOFS     VOLADDR(0x04000012, u16)
#define REG_BG1HOFS     VOLADDR(0x04000014, u16)
#define REG_BG1VOFS     VOLADDR(0x04000016, u16)
#define REG_BG2HOFS     VOLADDR(0x04000018, u16)
#define REG_BG2VOFS     VOLADDR(0x0400001A, u16)
#define REG_BG3HOFS     VOLADDR(0x0400001C, u16)
#define REG_BG3VOFS     VOLADDR(0x0400001E, u16)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_SCROLL_H */
