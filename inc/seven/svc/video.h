#ifndef _LIBSEVEN_SVC_VIDEO_H
#define _LIBSEVEN_SVC_VIDEO_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

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

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_VIDEO_H */