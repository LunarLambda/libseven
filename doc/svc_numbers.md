# SVC Numbers

This table lists all SVCs implemented by libseven.
Note that the ARM #s are the same as the THUMB #s, just shifted left 16 bits.

Name                    | # (THUMB) | # Hex (THUMB) | # (ARM) | # Hex (ARM)
:-----------------------|----------:|--------------:|--------:|-----------:
[SoftReset]             |         0 |          0x00 |       0 |   0x000000
[RegisterRamReset]      |         1 |          0x01 |   65536 |   0x010000
[Halt]                  |         2 |          0x02 |  131072 |   0x020000
[Stop]                  |         3 |          0x03 |  196608 |   0x030000
[IntrWait]              |         4 |          0x04 |  262144 |   0x040000
[VBlankIntrWait]        |         5 |          0x05 |  327680 |   0x050000
[Div]                   |         6 |          0x06 |  393216 |   0x060000
[Sqrt]                  |         8 |          0x08 |  524288 |   0x070000
[ArcTan]                |         9 |          0x09 |  589824 |   0x090000
[ArcTan2]               |        10 |          0x0A |  655360 |   0x0A0000
[CpuSet]                |        11 |          0x0B |  720896 |   0x0B0000
[CpuFastSet]            |        12 |          0x0C |  786432 |   0x0C0000
[BiosChecksum]          |        13 |          0x0D |  851968 |   0x0D0000
[BgAffineSet]           |        14 |          0x0E |  917504 |   0x0E0000
[ObjAffineSet]          |        15 |          0x0F |  983040 |   0x0F0000
[BitUnPack]             |        16 |          0x10 | 1048576 |   0x100000
[LZ77UnCompWram]        |        17 |          0x11 | 1114112 |   0x110000
[LZ77UnCompVram]        |        18 |          0x12 | 1179648 |   0x120000
[HuffUnComp]            |        19 |          0x13 | 1245184 |   0x130000
[RLUnCompWram]          |        20 |          0x14 | 1310720 |   0x140000
[RLUnCompVram]          |        21 |          0x15 | 1376256 |   0x150000
[Diff8bitUnFilterWram]  |        22 |          0x16 | 1441792 |   0x160000
[Diff8bitUnFilterVram]  |        23 |          0x17 | 1507328 |   0x170000
[Diff16bitUnFilter]     |        24 |          0x18 | 1572864 |   0x180000
[SoundBias]             |        25 |          0x19 | 1638400 |   0x190000
[SoundDriverInit]       |        26 |          0x1A | 1703936 |   0x1A0000
[SoundDriverMode]       |        27 |          0x1B | 1769472 |   0x1B0000
[SoundDriverMain]       |        28 |          0x1C | 1835008 |   0x1C0000
[SoundDriverVSync]      |        29 |          0x1D | 1900544 |   0x1D0000
[SoundChannelClear]     |        30 |          0x1E | 1966080 |   0x1E0000
[MidiKey2Freq]          |        31 |          0x1F | 2031616 |   0x1F0000
[MusicPlayerOpen]       |        32 |          0x20 | 2097152 |   0x200000
[MusicPlayerStart]      |        33 |          0x21 | 2162688 |   0x210000
[MusicPlayerStop]       |        34 |          0x22 | 2228224 |   0x220000
[MusicPlayerContinue]   |        35 |          0x23 | 2293760 |   0x230000
[MusicPlayerFadeOut]    |        36 |          0x24 | 2359296 |   0x240000
[MultiBoot]             |        37 |          0x25 | 2424832 |   0x250000
[HardReset]             |        38 |          0x26 | 2490368 |   0x260000
[SoundDriverVSyncOff]   |        40 |          0x28 | 2621440 |   0x280000
[SoundDriverVsyncOn]    |        41 |          0x29 | 2686976 |   0x290000

[SoftReset]: ./svc.md/#softreset
[RegisterRamReset]: ./svc.md/#registerramreset
[Halt]: ./svc.md/#halt
[Stop]: ./svc.md/#stop
[IntrWait]: ./svc.md/#intrwait
[VBlankIntrWait]: ./svc.md/#vblankintrwait
[Div]: ./svc.md/#div
[Sqrt]: ./svc.md/#sqrt
[ArcTan]: ./svc.md/#arctan
[ArcTan2]: ./svc.md/#arctan2
[CpuSet]: ./svc.md/#cpuset
[CpuFastSet]: ./svc.md/#cpufastset
[BiosChecksum]: ./svc.md/#bioschecksum
[BgAffineSet]: ./svc.md/#bgaffineset
[ObjAffineSet]: ./svc.md/#objaffineset
[BitUnPack]: ./svc.md/#bitunpack
[LZ77UnCompWram]: ./svc.md/#lz77uncompwram
[LZ77UnCompVram]: ./svc.md/#lz77uncompvram
[HuffUnComp]: ./svc.md/#huffuncomp
[RLUnCompWram]: ./svc.md/#rluncompwram
[RLUnCompVram]: ./svc.md/#rluncompvram
[Diff8bitUnFilterWram]: ./svc.md/#diff8bitunfilterwram
[Diff8bitUnFilterVram]: ./svc.md/#diff8bitunfiltervram
[Diff16bitUnFilter]: ./svc.md/#diff16bitunfilter
[SoundBias]: ./svc.md/#soundbias
[SoundDriverInit]: ./svc.md/#sounddriverinit
[SoundDriverMode]: ./svc.md/#sounddrivermode
[SoundDriverMain]: ./svc.md/#sounddrivermain
[SoundDriverVSync]: ./svc.md/#sounddrivervsync
[SoundChannelClear]: ./svc.md/#soundchannelclear
[MidiKey2Freq]: ./svc.md/#midikey2freq
[MusicPlayerOpen]: ./svc.md/#musicplayeropen
[MusicPlayerStart]: ./svc.md/#musicplayerstart
[MusicPlayerStop]: ./svc.md/#musicplayerstop
[MusicPlayerContinue]: ./svc.md/#musicplayercontinue
[MusicPlayerFadeOut]: ./svc.md/#musicplayerfadeout
[MultiBoot]: ./svc.md/#multiboot
[HardReset]: ./svc.md/#hardreset
[SoundDriverVSyncOff]: ./svc.md/#sounddrivervsyncoff
[SoundDriverVsyncOn]: ./svc.md/#sounddrivervsyncon
