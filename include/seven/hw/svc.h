/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_SVC_H
#define _LIBSEVEN_HW_SVC_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Just for reference, or if you want to use an inline SVC macro.
// I will not provide you with one, inline SVCs are a terrible idea!
// Not like you're losing much speed compared to the BIOS dispatch overhead...
enum SupervisorCallNumber
{
    SVC_SOFTRESET                       =  0,
    SVC_REGISTERRAMRESET                =  1,

    SVC_HALT                            =  2,
    SVC_STOP                            =  3,
    SVC_INTRWAIT                        =  4,
    SVC_VBLANKINTRWAIT                  =  5,

    SVC_DIV                             =  6,
    SVC_SQRT                            =  8,
    SVC_ARCTAN                          =  9,
    SVC_ARCTAN2                         = 10,

    SVC_CPUSET                          = 11,
    SVC_CPUFASTSET                      = 12,

    SVC_BIOSCHECKSUM                    = 13,

    SVC_BGAFFINESET                     = 14,
    SVC_OBJAFFINESET                    = 15,

    SVC_BITUNPACK                       = 16,
    SVC_LZ77UNCOMPWRAM                  = 17,
    SVC_LZ77UNCOMPVRAM                  = 18,
    SVC_HUFFUNCOMP                      = 19,
    SVC_RLUNCOMPWRAM                    = 20,
    SVC_RLUNCOMPVRAM                    = 21,
    SVC_DIFF8BITUNFILTERWRAM            = 22,
    SVC_DIFF8BITUNFILTERVRAM            = 23,
    SVC_DIFF16BITUNFILTER               = 24,

    SVC_SOUNDBIAS                       = 25,
    SVC_SOUNDDRIVERINIT                 = 26,
    SVC_SOUNDDRIVERMODE                 = 27,
    SVC_SOUNDDRIVERMAIN                 = 28,
    SVC_SOUNDDRIVERVSYNC                = 29,
    SVC_SOUNDCHANNELCLEAR               = 30,
    SVC_MIDIKEY2FREQ                    = 31,
    SVC_MUSICPLAYEROPEN                 = 32,
    SVC_MUSICPLAYERSTART                = 33,
    SVC_MUSICPLAYERSTOP                 = 34,
    SVC_MUSICPLAYERCONTINUE             = 35,
    SVC_MUSICPLAYERFADEOUT              = 36,

    SVC_MULTIBOOT                       = 37,

    SVC_HARDRESET                       = 38,

    SVC_SOUNDDRIVERVSYNCOFF             = 40,
    SVC_SOUNDDRIVERVSYNCON              = 41,
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SVC_H */
