# Supervisor Call Reference

Name                    | SVC Number | Implemented | Notes
:-----------------------|:----------:|:-----------:|:-----
SoftReset               |  0         | ✔️          |
RegisterRamReset        |  1         | ✔️          |
Halt                    |  2         | ✔️          |
Stop                    |  3         | ✔️          |
IntrWait                |  4         | ✔️          |
VBlankIntrWait          |  5         | ✔️          |
Div                     |  6         | ✔️          |
DivArm                  |  7         | ❌          | Redundant
Sqrt                    |  8         | ✔️          |
ArcTan                  |  9         | ✔️          |
ArcTan2                 | 10         | ✔️          |
CpuSet                  | 11         | ✔️          |
CpuFastSet              | 12         | ✔️          |
BiosChecksum            | 13         | ✔️          | Undocumented
BgAffineSet             | 14         | ✔️          |
ObjAffineSet            | 15         | ✔️          |
BitUnPack               | 16         | ✔️          |
LZ77UnCompWram          | 17         | ✔️          |
LZ77UnCompVram          | 18         | ✔️          |
HuffUnComp              | 19         | ✔️          |
RLUnCompWram            | 20         | ✔️          |
RLUnCompVram            | 21         | ✔️          |
Diff8bitUnFilterWram    | 22         | ✔️          |
Diff8bitUnFilterVram    | 23         | ✔️          |
Diff16bitUnFilter       | 24         | ✔️          |
SoundBiasChange         | 25         | ❌          |
SoundDriverInit         | 26         | ❌          |
SoundDriverMode         | 27         | ❌          |
SoundDriverMain         | 28         | ✔️          |
SoundDriverVSync        | 29         | ✔️          |
SoundDriverChannelClear | 30         | ✔️          |
MidiKey2Freq            | 31         | ❌          |
MusicPlayerOpen         | 32         | ❌          |
MusicPlayerStart        | 33         | ❌          |
MusicPlayerStop         | 34         | ❌          |
MusicPlayerContinue     | 35         | ❌          |
MusicPlayerFadeOut      | 36         | ❌          |
MultiBoot               | 37         | ❌          |
HardReset               | 38         | ✔️          | Undocumented, resets back to BIOS start animation
?                       | 39         | ❌          | Undocumented, used internally by Stop/Halt
SoundDriverVSyncOff     | 40         | ✔️          |
SoundDriverVSyncOn      | 41         | ✔️          |
?                       | 42         | ❌          | Undocumented, copies pointers to sound related functions
