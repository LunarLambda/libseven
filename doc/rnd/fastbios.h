/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_UTIL_FASTBIOS_H
#define _LIBSEVEN_UTIL_FASTBIOS_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

enum BiosFunctionAddress
{
    BIOSADDR_SOFTRESET                  = 0x00B4,
    BIOSADDR_REGISTERRAMRESET           = 0x09C3, /* THUMB */
    BIOSADDR_HALT                       = 0x01A0,
    BIOSADDR_STOP                       = 0x01A8,
    BIOSADDR_INTRWAIT                   = 0x0330,
    BIOSADDR_VBLANKINTRWAIT             = 0x0328,
    BIOSADDR_DIV                        = 0x03B4,
    /* SVC 7 / DIVARM */
    BIOSADDR_SQRT                       = 0x0404,
    BIOSADDR_ARCTAN                     = 0x0474,
    BIOSADDR_ARCTAN2                    = 0x04FD, /* THUMB */
    BIOSADDR_CPUSET                     = 0x0B4D, /* THUMB */
    BIOSADDR_CPUFASTSET                 = 0x0BC4,
    BIOSADDR_BIOSCHECKSUM               = 0x0378,
    BIOSADDR_OBJAFFINESET               = 0x0C2C,
    BIOSADDR_BGAFFINESET                = 0x0CE0,
    BIOSADDR_BITUNPACK                  = 0x0F60,
    BIOSADDR_LZ77UNCOMPWRAM             = 0x10FC,
    BIOSADDR_LZ77UNCOMPVRAM             = 0x1194,
    BIOSADDR_HUFFUNCOMP                 = 0x1014,
    BIOSADDR_RLUNCOMPWRAM               = 0x1279, /* THUMB */
    BIOSADDR_RLUNCOMPVRAM               = 0x12C1, /* THUMB */
    BIOSADDR_DIFF8BITUNFILTERWRAM       = 0x1333, /* THUMB */
    BIOSADDR_DIFF8BITUNFILTERVRAM       = 0x135D, /* THUMB */
    BIOSADDR_DIFF16BITUNFILTER          = 0x1399, /* THUMB */
    BIOSADDR_SOUNDBIAS                  = 0x0801, /* THUMB */
    BIOSADDR_SOUNDDRIVERINIT            = 0x1665, /* THUMB */
    BIOSADDR_SOUNDDRIVERMODE            = 0x179D, /* THUMB */
    BIOSADDR_SOUNDDRIVERMAIN            = 0x1DC5, /* THUMB */
    BIOSADDR_SOUNDDRIVERVSYNC           = 0x210D, /* THUMB */
    BIOSADDR_SOUNDCHANNELCLEAR          = 0x1825, /* THUMB */
    BIOSADDR_MIDIKEY2FREQ               = 0x18D9, /* THUMB */
    BIOSADDR_MUSICPLAYEROPEN            = 0x13C5, /* THUMB */
    BIOSADDR_MUSICPLAYERSTART           = 0x1435, /* THUMB */
    BIOSADDR_MUSICPLAYERSTOP            = 0x14C1, /* THUMB */
    BIOSADDR_MUSICPLAYERCONTINUE        = 0x14FD, /* THUMB */
    BIOSADDR_MUSICPLAYERFADEOUT         = 0x1515, /* THUMB */
    BIOSADDR_MULTIBOOT                  = 0x28CF, /* THUMB */
    BIOSADDR_HARDRESET                  = 0x008C,
    /* SVC 39 */
    BIOSADDR_SOUNDDRIVERVSYNCOFF        = 0x1879, /* THUMB */
    BIOSADDR_SOUNDDRIVERVSYNCON         = 0x18C9, /* THUMB */
    /* SVC 42 */
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_FASTBIOS_H */
