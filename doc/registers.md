# I/O Register Reference

Address     | Size | Access | GBATEK      | libgba          | libtonc     | libseven
:----------:|:----:|:------:|:------------|:----------------|:------------|:--------
[0400 0000] | 16   | R/W    | DISPCNT     | DISPCNT         | DISPCNT [¹] | DISPCNT
 0400 0004  | 16   | R/W    | DISPSTAT    | DISPSTAT        | DISPSTAT    | DISPSTAT
 0400 0006  | 16/8 | R      | VCOUNT      | VCOUNT [²]      | VCOUNT [²]  | VCOUNT
 0400 0008  | 16   | R/W    | BG0CNT      | BG0CNT          | BG0CNT      | BG0CNT
 0400 000A  | 16   | R/W    | BG1CNT      | BG1CNT          | BG1CNT      | BG1CNT
 0400 000C  | 16   | R/W    | BG2CNT      | BG2CNT          | BG2CNT      | BG2CNT
 0400 000E  | 16   | R/W    | BG3CNT      | BG3CNT          | BG3CNT      | BG3CNT
 0400 0010  | 16   | W      | BG0HOFS     | BG0HOFS [³]     | BG0HOFS     | BG0HOFS
 0400 0012  | 16   | W      | BG0VOFS     | BG0VOFS [³]     | BG0VOFS     | BG0VOFS
 0400 0014  | 16   | W      | BG1HOFS     | BG1HOFS [³]     | BG1HOFS     | BG1HOFS
 0400 0016  | 16   | W      | BG1VOFS     | BG1VOFS [³]     | BG1VOFS     | BG1VOFS
 0400 0018  | 16   | W      | BG2HOFS     | BG2HOFS [³]     | BG2HOFS     | BG2HOFS
 0400 001A  | 16   | W      | BG2VOFS     | BG2VOFS [³]     | BG2VOFS     | BG2VOFS
 0400 001C  | 16   | W      | BG3HOFS     | BG3HOFS [³]     | BG3HOFS     | BG3HOFS
 0400 001E  | 16   | W      | BG3VOFS     | BG3VOFS [³]     | BG3VOFS     | BG3VOFS
 0400 0020  | 16   | W      | BG2PA       | BG2PA [³]       | BG2PA       | BG2PA
 0400 0022  | 16   | W      | BG2PB       | BG2PB [³]       | BG2PB       | BG2PB
 0400 0024  | 16   | W      | BG2PC       | BG2PC [³]       | BG2PC       | BG2PC
 0400 0026  | 16   | W      | BG2PD       | BG2PD [³]       | BG2PD       | BG2PD
 0400 0028  | 32   | W      | BG2X        | BG2X [³]        | BG2X [⁴]    | BG2X
 0400 002C  | 32   | W      | BG2Y        | BG2Y [³]        | BG2Y [⁴]    | BG2Y
 0400 0030  | 16   | W      | BG3PA       | BG3PA [³]       | BG3PA       | BG3PA
 0400 0032  | 16   | W      | BG3PB       | BG3PB [³]       | BG3PB       | BG3PB
 0400 0034  | 16   | W      | BG3PC       | BG3PC [³]       | BG3PC       | BG3PC
 0400 0036  | 16   | W      | BG3PD       | BG3PD [³]       | BG3PD       | BG3PD
 0400 0038  | 32   | W      | BG3X        | BG3X [³]        | BG3X [⁴]    | BG3X
 0400 003C  | 32   | W      | BG3Y        | BG3Y [³]        | BG3Y [⁴]    | BG3Y
 0400 0040  | 16   | W      | WIN0H       | WIN0H           | WIN0H       | WIN0H
 0400 0042  | 16   | W      | WIN1H       | WIN1H           | WIN1H       | WIN1H
 0400 0044  | 16   | W      | WIN0V       | WIN0V           | WIN0V       | WIN0V
 0400 0046  | 16   | W      | WIN1V       | WIN1V           | WIN1V       | WIN1V
 0400 0048  | 16   | R/W    | WININ       | WININ           | WININ       | WININ
 0400 004A  | 16   | R/W    | WINOUT      | WINOUT          | WINOUT      | WINOUT
 0400 004C  | 16   | W      | MOSAIC      | MOSAIC          | MOSAIC      | MOSAIC
 0400 0050  | 16   | R/W    | BLDCNT      | BLDCNT          | BLDCNT      | BLDCNT
 0400 0052  | 16   | R/W    | BLDALPHA    | BLDALPHA        | BLDALPHA    | BLDALPHA
 0400 0054  | 16   | W      | BLDY        | BLDY            | BLDY        | **BLDVAL**
​|||||||
 0400 0060  | 16   | R/W    | SOUND1CNT_L | SOUND1CNT_L     | SOUND1CNT_L | -
 0400 0062  | 16   | R/W    | SOUND1CNT_H | SOUND1CNT_H     | SOUND1CNT_H | -
 0400 0064  | 16   | R/W    | SOUND1CNT_X | SOUND1CNT_X     | SOUND1CNT_X | -
 0400 0068  | 16   | R/W    | SOUND2CNT_L | SOUND2CNT_L     | SOUND2CNT_L | -
 0400 006C  | 16   | R/W    | SOUND2CNT_H | SOUND2CNT_H     | SOUND2CNT_H | -
 0400 0070  | 16   | R/W    | SOUND3CNT_L | SOUND3CNT_L     | SOUND3CNT_L | -
 0400 0072  | 16   | R/W    | SOUND3CNT_H | SOUND3CNT_H     | SOUND3CNT_H | -
 0400 0074  | 16   | R/W    | SOUND3CNT_X | SOUND3CNT_X     | SOUND3CNT_X | -
 0400 0078  | 16   | R/W    | SOUND4CNT_L | SOUND4CNT_L     | SOUND4CNT_L | -
 0400 007C  | 16   | R/W    | SOUND4CNT_H | SOUND4CNT_H     | SOUND4CNT_H | -
 0400 0080  | 16   | R/W    | SOUNDCNT_L  | SOUNDCNT_L      | SOUNDCNT_L  | -
 0400 0082  | 16   | R/W    | SOUNDCNT_H  | SOUNDCNT_H      | SOUNDCNT_H  | -
 0400 0084  | 16   | R/W    | SOUNDCNT_X  | SOUNDCNT_X      | SOUNDCNT_X  | -
 0400 0088  | 16   | R/W    | SOUNDBIAS   | SOUNDBIAS       | SOUNDBIAS   | -
 0400 0090  | 32x4 | R/W    | WAVE_RAM    | WAVE_RAM        | WAVE_RAM [¹]| -
 0400 00A0  | 32   | W      | FIFO_A      | FIFO_A          | FIFO_A      | -
 0400 00A4  | 32   | W      | FIFO_B      | FIFO_B          | FIFO_B      | -
​|||||||
 0400 00B0  | 32   | W      | DMA0SAD     | DMA0SAD         | DMA0SAD     | **DMA0SRC**
 0400 00B4  | 32   | W      | DMA0DAD     | DMA0DAD         | DMA0DAD     | **DMA0DST**
 0400 00B8  | 16   | W      | DMA0CNT_L   | **DMA0CNT** [¹] | DMA0CNT_L   | **DMA0LEN**
[0400 00BA] | 16   | R/W    | DMA0CNT_H   | -               | DMA0CNT_H   | **DMA0CNT**
 0400 00BC  | 32   | W      | DMA1SAD     | DMA1SAD         | DMA1SAD     | **DMA1SRC**
 0400 00C0  | 32   | W      | DMA1DAD     | DMA1DAD         | DMA1DAD     | **DMA1DST**
 0400 00C4  | 16   | W      | DMA1CNT_L   | **DMA1CNT** [¹] | DMA1CNT_L   | **DMA1LEN**
[0400 00C6] | 16   | R/W    | DMA1CNT_H   | -               | DMA1CNT_H   | **DMA1CNT**
 0400 00C8  | 32   | W      | DMA2SAD     | DMA2SAD         | DMA2SAD     | **DMA2SRC**
 0400 00CC  | 32   | W      | DMA2DAD     | DMA2DAD         | DMA2DAD     | **DMA2DST**
 0400 00D0  | 16   | W      | DMA2CNT_L   | **DMA2CNT** [¹] | DMA2CNT_L   | **DMA2LEN**
[0400 00D2] | 16   | R/W    | DMA2CNT_H   | -               | DMA2CNT_H   | **DMA2CNT**
 0400 00D4  | 32   | W      | DMA3SAD     | DMA3SAD         | DMA3SAD     | **DMA3SRC**
 0400 00D8  | 32   | W      | DMA3DAD     | DMA3DAD         | DMA3DAD     | **DMA3DST**
 0400 00DC  | 16   | W      | DMA3CNT_L   | **DMA3CNT** [¹] | DMA3CNT_L   | **DMA3LEN**
[0400 00DE] | 16   | R/W    | DMA3CNT_H   | -               | DMA3CNT_H   | **DMA3CNT**
​|||||||
 0400 0100  | 16   | R/W    | TM0CNT_L    | TM0CNT_L        | TM0CNT_L    | **TM0VAL**
 0400 0102  | 16   | R/W    | TM0CNT_H    | TM0CNT_H        | TM0CNT_H    | **TM0CNT**
 0400 0104  | 16   | R/W    | TM1CNT_L    | TM1CNT_L        | TM1CNT_L    | **TM1VAL**
 0400 0106  | 16   | R/W    | TM1CNT_H    | TM1CNT_H        | TM1CNT_H    | **TM1CNT**
 0400 0108  | 16   | R/W    | TM2CNT_L    | TM2CNT_L        | TM2CNT_L    | **TM2VAL**
 0400 010A  | 16   | R/W    | TM2CNT_H    | TM2CNT_H        | TM2CNT_H    | **TM2CNT**
 0400 010C  | 16   | R/W    | TM3CNT_L    | TM3CNT_L        | TM3CNT_L    | **TM3VAL**
 0400 010E  | 16   | R/W    | TM3CNT_H    | TM3CNT_H        | TM3CNT_H    | **TM3CNT**
​|||||||
 0400 0120  | 32   | R/W    | SIODATA32   | SIODATA32       | SIODATA32   | SIODATA32
 0400 0120  | 16   | R/W    | SIOMULTI0   | SIOMULTI0       | SIOMULTI0   | -
 0400 0122  | 16   | R/W    | SIOMULTI1   | SIOMULTI1       | SIOMULTI1   | -
 0400 0124  | 16   | R/W    | SIOMULTI2   | SIOMULTI2       | SIOMULTI2   | -
 0400 0126  | 16   | R/W    | SIOMULTI3   | SIOMULTI3       | SIOMULTI3   | -
 0400 0128  | 16   | R/W    | SIOCNT      | SIOCNT          | SIOCNT      | SIOCNT
 0400 012A  | 16   | R/W    | SIOMLT_SEND | SIOMLT_SEND     | SIOMLT_SEND | -
 0400 012A  | 16/8 | R/W    | SIODATA8    | SIODATA8        | SIODATA8    | SIODATA8
​|||||||
 0400 0130  | 16   | R      | KEYINPUT    | KEYINPUT [²]    | KEYINPUT [²]| KEYINPUT
 0400 0132  | 16   | R/W    | KEYCNT      | KEYCNT          | KEYCNT      | KEYCNT
​|||||||
 0400 0134  | 16   | R/W    | RCNT        | RCNT            | RCNT        | **SIOMODE2**
 0400 0140  | 16   | R/W    | JOYCNT      | **HS_CTRL**     | JOYCNT      | -
 0400 0150  | 32   | R/W    | JOY_RECV    | **JOYRE**       | JOY_RECV    | -
 0400 0154  | 32   | R/W    | JOY_TRANS   | **JOYTR**       | JOY_TRANS   | -
 0400 0158  | 16   | R      | JOYSTAT     | **JSTAT** [²]   | JOYSTAT [²] | -
​|||||||
[0400 0200] | 16   | R/W    | IE          | IE              | IE          | IE
 0400 0202  | 16   | R/W    | IF          | IF              | IF          | IF
 0400 0204  | 16   | R/W    | WAITCNT     | -               | WAITCNT     | WAITCNT
 0400 0208  | 16/1 | R/W    | IME         | IME             | IME         | IME

## Errata

1. Register is not marked as 16-bit
2. Register is not marked as read-only
3. Register is not marked as volatile

[¹]: #errata
[²]: #errata
[³]: #errata

[0400 0000]: io/dispcnt.md
[0400 00BA]: io/dmacnt.h
[0400 00C6]: io/dmacnt.h
[0400 00D2]: io/dmacnt.h
[0400 00DE]: io/dmacnt.h
[0400 0200]: io/ie.md
