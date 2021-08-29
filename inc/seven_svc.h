#ifndef _LIBSEVEN_SVC_H
#define _LIBSEVEN_SVC_H

#include <seven_base.h>

// Just for reference, or if you want to use an inline SVC macro.
// I will not provide you with one, inline SVCs are a terrible idea!
// Not like you're losing much speed compared to the BIOS dispatch overhead...
enum SupervisorCallNumber
{
    SVC_SOFTRESET               =  0,
    SVC_REGISTERRAMRESET        =  1,

    SVC_HALT                    =  2,
    SVC_STOP                    =  3,
    SVC_INTRWAIT                =  4,
    SVC_VBLANKINTRWAIT          =  5,

    SVC_DIV                     =  6,
    SVC_DIVARM                  =  7,
    SVC_SQRT                    =  8,
    SVC_ARCTAN                  =  9,
    SVC_ARCTAN2                 = 10,

    SVC_CPUSET                  = 11,
    SVC_CPUFASTSET              = 12,

    // Undocumented
    SVC_BIOSCHECKSUM            = 13,

    SVC_BGAFFINESET             = 14,
    SVC_OBJAFFINESET            = 15,

    SVC_BITUNPACK               = 16,
    SVC_LZ77UNCOMPWRAM          = 17,
    SVC_LZ77UNCOMPVRAM          = 18,
    SVC_HUFFUNCOMP              = 19,
    SVC_RLUNCOMPWRAM            = 20,
    SVC_RLUNCOMPVRAM            = 21,
    SVC_DIFF8BITUNFILTERWRAM    = 22,
    SVC_DIFF8BITUNFILTERVRAM    = 23,
    SVC_DIFF16BITUNFILTER       = 24,

    SVC_SOUNDBIAS               = 25,
    SVC_SOUNDDRIVERINIT         = 26,
    SVC_SOUNDDRIVERMODE         = 27,
    SVC_SOUNDDRIVERMAIN         = 28,
    SVC_SOUNDDRIVERVSYNC        = 29,
    SVC_SOUNDCHANNELCLEAR       = 30,
    SVC_MIDIKEY2FREQ            = 31,
    SVC_MUSICPLAYEROPEN         = 32,
    SVC_MUSICPLAYERSTART        = 33,
    SVC_MUSICPLAYERSTOP         = 34,
    SVC_MUSICPLAYERCONTINUE     = 35,
    SVC_MUSICPLAYERFADEOUT      = 36,

    SVC_MULTIBOOT               = 37,

    // Undocumented
    SVC_HARDRESET               = 38,

    SVC_SOUNDDRIVERVSYNCOFF     = 40,
    SVC_SOUNDDRIVERVSYNCON      = 41,

    // Undocumented and most likely not useful
     SVC_INTERNALHALT         = 39,
     SVC_SOUNDGETFUNCTIONS    = 42,
};

extern void NORETURN svcSoftReset(void);
extern void NORETURN svcHardReset(void);

enum SoftResetExFlags
{
    SRE_FROM_ROM = 0,
    SRE_FROM_RAM = 1,
};

// Combines svcRegisterRamReset and svcSoftReset
// Allows reset from EWRAM, automatically unsets RRR_EWRAM
// Disables IME to prevent IRQs crashing from a dangling handler
extern void NORETURN svcSoftResetEx(u8 reset_flags, bool from_ewram)

enum RegisterRamResetFlags
{
    RRR_EWRAM           = BIT(0),
    RRR_IWRAM           = BIT(1),
    RRR_PALETTE         = BIT(2),
    RRR_VRAM            = BIT(3),
    RRR_OAM             = BIT(4),
    RRR_SIO             = BIT(5),
    RRR_SOUND           = BIT(6),
    RRR_REGISTERS       = BIT(7),
    RRR_EVERYTHING      = BITS(0, 8),
};

extern void svcRegisterRamReset(u8 reset_flags);

extern void svcHalt(void);
extern void svcStop(void);
extern void svcIntrWait(bool wait_next, u16 intr_flags);
extern void svcVBlankIntrWait(void);

struct Div
{
    i32 quot;
    i32 rem;
};

extern struct Div svcDiv(i32 numerator, i32 denominator);
extern u16 svcSqrt(u32 x);
extern i16 ArcTan(i16 tan);
extern u16 ArcTan2(i16 x, i16 y);

enum CpuSetFlags
{
    CS_SRC_FIXED        = BIT(24),
    CS_32BIT            = BIT(26),
    CS_16BIT            = !CS_32BIT,
};

extern void svcCpuSet(const void *src, void *dst, u32 ctrl);

enum CpuFastSetFlags
{
    CFS_SRC_FIXED       = BIT(24),
};

extern void svcCpuFastSet(const void *src, void *dst, u32 ctrl);

extern u32 svcBiosChecksum(void);
extern bool svcIsSystemDS(void);

struct BgAffineSrcData
{
    i32 src_center_x;
    i32 src_center_y;
    i16 disp_center_x;
    i16 disp_center_y;
    i16 ratio_x;
    i16 ratio_y;
    u16 theta;
};

struct BgAffineDstData
{
    i16 h_diff_x;
    i16 v_diff_x;
    i16 h_diff_y;
    i16 v_diff_y;
    i32 start_x;
    i32 start_y;
};

extern void svcBgAffineSet(
    const struct BgAffineSrcData *src,
    struct BgAffineDstData *dst,
    u32 num);

struct ObjAffineSrcData
{
    i16 ratio_x;
    i16 ratio_y;
    u16 theta;
};

struct ObjAffineDstData
{
    i16 h_diff_x;
    i16 v_diff_x;
    i16 h_diff_y;
    i16 v_diff_y;
};

enum ObjAffineSetOffset
{
    OAS_LIKE_DSTDATA    = 2,
    OAS_LIKE_OAM        = 8,
};

extern void svcObjAffineSet(
        const struct ObjAffineSrcData *src,
        void *dst,
        u32 num,
        u32 offset);

struct BitUnPackParam
{
    u16 src_length;     // in bytes
    u8  src_width;      // width of each src element (1, 2, 4, 8)
    u8  dst_width;      // width of each dst element (1, 2, 4, 8, 16, 32)
    u32 offset:31;      // value to add to each dst element
    u32 keep_zeroes:1;  // whether to add offset to zero elements too
};

extern void svcBitUnPack(
        const void *src,
        void *dst,
        const struct BitUnPackParam *param);

// TODO: Separate header? Need extra structures.
extern void svcLZ77UnCompWram(const void *src, void *dst);
extern void svcLZ77UnCompVram(const void *src, void *dst);
extern void svcHuffUnComp(const void *src, void *dst);
extern void svcRLUnCompWram(const void *src, void *dst);
extern void svcRLUnCompVram(const void *src, void *dst);
extern void svcDiff8bitUnFilterWram(const void *src, void *dst);
extern void svcDiff8bitUnFilterVram(const void *src, void *dst);
extern void svcDiff16bitUnFilter(const void *src, void *dst);

// TODO: Separate header? Need extra structures, plus really rarely used.
extern void svcSoundDriverMain(void);
extern void svcSoundDriverVSync(void);
extern void svcSoundChannelClear(void);
extern void svcSoundDriverVSyncOff(void);
extern void svcSoundDriverVSyncOn(void);

// TODO: MusicPlayer* functions

#endif /* !_LIBSEVEN_SVC_H */
