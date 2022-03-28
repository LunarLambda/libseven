/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_COLOR_H
#define _LIBSEVEN_VIDEO_COLOR_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

#define BF_COLOR_R_OFFSET 0
#define BF_COLOR_R_LENGTH 5

#define COLOR_R(n) BITFIELD(COLOR_R, (n))

#define BF_COLOR_G_OFFSET 5
#define BF_COLOR_G_LENGTH 5

#define COLOR_G(n) BITFIELD(COLOR_G, (n))

#define BF_COLOR_B_OFFSET 10
#define BF_COLOR_B_LENGTH 5

#define COLOR_B(n) BITFIELD(COLOR_B, (n))

#define RGB5(r, g, b) \
    ((u16)(COLOR_R((r)) | COLOR_G((g)) | COLOR_B((b))))

#define RGB8(r, g, b) \
    RGB5((r) >> 3, (g) >> 3, (b) >> 3)

#define COLOR_RED               RGB5(31,  0,  0)
#define COLOR_RED_ORANGE        RGB5(31,  8,  0)
#define COLOR_ORANGE            RGB5(31, 15,  0)
#define COLOR_ORANGE_YELLOW     RGB5(31, 23,  0)
#define COLOR_YELLOW            RGB5(31, 31,  0)
#define COLOR_YELLOW_LIME       RGB5(23, 31,  0)
#define COLOR_LIME              RGB5(15, 31,  0)
#define COLOR_LIME_GREEN        RGB5( 8, 31,  0)
#define COLOR_GREEN             RGB5( 0, 31,  0)
#define COLOR_GREEN_MINT        RGB5( 0, 31,  8)
#define COLOR_MINT              RGB5( 0, 31, 15)
#define COLOR_MINT_CYAN         RGB5( 0, 31, 23)
#define COLOR_CYAN              RGB5( 0, 31, 31)
#define COLOR_CYAN_SKYBLUE      RGB5( 0, 23, 31)
#define COLOR_SKYBLUE           RGB5( 0, 15, 31)
#define COLOR_SKYBLUE_BLUE      RGB5( 0,  8, 31)
#define COLOR_BLUE              RGB5( 0,  0, 31)
#define COLOR_BLUE_PURPLE       RGB5( 8,  0, 31)
#define COLOR_PURPLE            RGB5(15,  0, 31)
#define COLOR_PURPLE_MAGENTA    RGB5(23,  0, 31)
#define COLOR_MAGENTA           RGB5(31,  0, 31)
#define COLOR_MAGENTA_PINK      RGB5(31,  0, 23)
#define COLOR_PINK              RGB5(31,  0, 15)
#define COLOR_PINK_RED          RGB5(31,  0,  8)

#define COLOR_WHITE             RGB5(31, 31, 31)
#define COLOR_BLACK             RGB5( 0,  0,  0)

#define COLOR_GRAY_100          RGB5(31, 31, 31)
#define COLOR_GRAY_95           RGB5(29, 29, 29)
#define COLOR_GRAY_90           RGB5(28, 28, 28)
#define COLOR_GRAY_85           RGB5(26, 26, 26)
#define COLOR_GRAY_80           RGB5(25, 25, 25)
#define COLOR_GRAY_75           RGB5(23, 23, 23)
#define COLOR_GRAY_70           RGB5(22, 22, 22)
#define COLOR_GRAY_65           RGB5(20, 20, 20)
#define COLOR_GRAY_60           RGB5(19, 19, 19)
#define COLOR_GRAY_55           RGB5(17, 17, 17)
#define COLOR_GRAY_50           RGB5(15, 15, 15)
#define COLOR_GRAY_45           RGB5(14, 14, 14)
#define COLOR_GRAY_40           RGB5(12, 12, 12)
#define COLOR_GRAY_35           RGB5(11, 11, 11)
#define COLOR_GRAY_30           RGB5( 9,  9,  9)
#define COLOR_GRAY_25           RGB5( 8,  8,  8)
#define COLOR_GRAY_20           RGB5( 6,  6,  6)
#define COLOR_GRAY_15           RGB5( 5,  5,  5)
#define COLOR_GRAY_10           RGB5( 3,  3,  3)
#define COLOR_GRAY_5            RGB5( 2,  2,  2)
#define COLOR_GRAY_0            RGB5( 0,  0,  0)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_COLOR_H */
