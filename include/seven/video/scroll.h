/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_SCROLL_H
#define _LIBSEVEN_VIDEO_SCROLL_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_BG0HOFS     REG16(0x04000010)
#define REG_BG0VOFS     REG16(0x04000012)
#define REG_BG1HOFS     REG16(0x04000014)
#define REG_BG1VOFS     REG16(0x04000016)
#define REG_BG2HOFS     REG16(0x04000018)
#define REG_BG2VOFS     REG16(0x0400001A)
#define REG_BG3HOFS     REG16(0x0400001C)
#define REG_BG3VOFS     REG16(0x0400001E)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_SCROLL_H */
