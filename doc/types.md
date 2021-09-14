# seven\_types.h

[Link to header](../inc/seven_types.h)

## Synopsis

This header provides the base types used by libseven.
It also provides \*\_MIN and \*\_MAX constants for all integer types.

## Signed Types

Type Name       | Alias for 
----------------|-----------
i8, s8          | int8\_t
i16, s16        | int16\_t
i32, s32        | int32\_t
i64, s64        | int64\_t
isize, ssize    | ptrdiff\_t
iptr, sptr      | intptr\_t

## Unsigned Types

Type Name       | Alias for 
----------------|-----------
u8              | uint8\_t
u16             | uint16\_t
u32             | uint32\_t
u64             | uint64\_t
usize           | size\_t
uptr            | uintptr\_t

## Register Types

These types are used for register definitions.

Type Name       | Alias for
----------------|----------
reg8            | volatile u8
reg16           | volatile u16
reg32           | volatile u32

## Other Types

The following standard C headers are included:

- \<limits.h\>
- \<stdbool.h\>
- \<stddef.h\>
- \<stdint.h\>
