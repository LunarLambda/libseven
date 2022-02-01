@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_SVC_S
.equiv   _LIBSEVEN_ASM_HW_SVC_S, 1

.include "seven/asm/base.s"

CONST SVC_SOFTRESET,             0
CONST SVC_REGISTERRAMRESET,      1
CONST SVC_HALT,                  2
CONST SVC_STOP,                  3
CONST SVC_INTRWAIT,              4
CONST SVC_VBLANKINTRWAIT,        5
CONST SVC_DIV,                   6
CONST SVC_SQRT,                  8
CONST SVC_ARCTAN,                9
CONST SVC_ARCTAN2,              10
CONST SVC_CPUSET,               11
CONST SVC_CPUFASTSET,           12
CONST SVC_BIOSCHECKSUM,         13
CONST SVC_BGAFFINESET,          14
CONST SVC_OBJAFFINESET,         15
CONST SVC_BITUNPACK,            16
CONST SVC_LZ77UNCOMPWRAM,       17
CONST SVC_LZ77UNCOMPVRAM,       18
CONST SVC_HUFFUNCOMP,           19
CONST SVC_RLUNCOMPWRAM,         20
CONST SVC_RLUNCOMPVRAM,         21
CONST SVC_DIFF8BITUNFILTERWRAM, 22
CONST SVC_DIFF8BITUNFILTERVRAM, 23
CONST SVC_DIFF16BITUNFILTER,    24
CONST SVC_SOUNDBIAS,            25
CONST SVC_SOUNDDRIVERINIT,      26
CONST SVC_SOUNDDRIVERMODE,      27
CONST SVC_SOUNDDRIVERMAIN,      28
CONST SVC_SOUNDDRIVERVSYNC,     29
CONST SVC_SOUNDCHANNELCLEAR,    30
CONST SVC_MIDIKEY2FREQ,         31
CONST SVC_MUSICPLAYEROPEN,      32
CONST SVC_MUSICPLAYERSTART,     33
CONST SVC_MUSICPLAYERSTOP,      34
CONST SVC_MUSICPLAYERCONTINUE,  35
CONST SVC_MUSICPLAYERFADEOUT,   36
CONST SVC_MULTIBOOT,            37
CONST SVC_HARDRESET,            38
CONST SVC_SOUNDDRIVERVSYNCOFF,  40
CONST SVC_SOUNDDRIVERVSYNCON,   41

EXTFN svcSoftReset
EXTFN svcRegisterRamReset
EXTFN svcHalt
EXTFN svcStop
EXTFN svcIntrWait
EXTFN svcVBlankIntrWait
EXTFN svcSqrt
EXTFN svcArcTan
EXTFN svcArcTan2
EXTFN svcCpuSet
EXTFN svcCpuFastSet
EXTFN svcBiosChecksum
EXTFN svcBgAffineSet
EXTFN svcObjAffineSet
EXTFN svcBitUnPack
EXTFN svcLZ77UnCompWram
EXTFN svcLZ77UnCompVram
EXTFN svcHuffUnComp
EXTFN svcRLUnCompWram
EXTFN svcRLUnCompVram
EXTFN svcDiff8bitUnFilterWram
EXTFN svcDiff8bitUnFilterVram
EXTFN svcDiff16bitUnFilter
EXTFN svcSoundBiasChange
EXTFN svcSoundDriverInit
EXTFN svcSoundDriverMode
EXTFN svcSoundDriverMain
EXTFN svcSoundDriverVSync
EXTFN svcSoundChannelClear
EXTFN svcMidiKey2Freq
EXTFN svcMusicPlayerOpen
EXTFN svcMusicPlayerStart
EXTFN svcMusicPlayerStop
EXTFN svcMusicPlayerContinue
EXTFN svcMusicPlayerFadeOut
EXTFN svcMultiBoot
EXTFN svcHardReset
EXTFN svcSoundDriverVSyncOff
EXTFN svcSoundDriverVSyncOn

EXTFN svcSoftResetEx
EXTFN svcIntrWaitEx
EXTFN svcCpuSetFixed
EXTFN svcCpuFastSetFixed
EXTFN svcIsSystemDS

.endif @ !_LIBSEVEN_ASM_HW_SVC_S

@ vim: ft=armv4 et sta sw=4 sts=8
