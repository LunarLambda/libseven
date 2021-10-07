#ifndef _LIBSEVEN_MATH_H
#define _LIBSEVEN_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

struct Div
{
    i32 quot;
    i32 rem;
};

extern struct Div svcDiv(i32 numerator, i32 denominator);
extern u16 svcSqrt(u32 x);
extern i16 svcArcTan(i16 tan);
extern u16 svcArcTan2(i16 x, i16 y);

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_MATH_H */
