#ifndef _LIBSEVEN_SVC_COMPRESSION_H
#define _LIBSEVEN_SVC_COMPRESSION_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

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

extern void svcLZ77UnCompWram(const void *src, void *dst);
extern void svcLZ77UnCompVram(const void *src, void *dst);
extern void svcHuffUnComp(const void *src, void *dst);
extern void svcRLUnCompWram(const void *src, void *dst);
extern void svcRLUnCompVram(const void *src, void *dst);
extern void svcDiff8bitUnFilterWram(const void *src, void *dst);
extern void svcDiff8bitUnFilterVram(const void *src, void *dst);
extern void svcDiff16bitUnFilter(const void *src, void *dst);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_COMPRESSION_H */
