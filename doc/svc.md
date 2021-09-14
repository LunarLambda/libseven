# seven\_svc.h

[Link to header](../inc/seven_svc.h)

## Synopsis

This header provides the definitions for all functions provided by the GBA BIOS,
also known as SWIs (Software Interrupts) or SVCs (Supervisor Calls).

TODO: Table of contents here

## Functions

### svcSoftReset

#### C Function Signature

```c
void NORETURN svcSoftReset(void)
```

#### SVC Number

\#0 (THUMB), \#0 (ARM)

#### Description

This function soft-resets the console. This resets the stack pointers
to their initial values. The entry point (EWRAM or ROM) is chosen based
on the value in MULTIBOOT\_FLAG (TODO: Name this better)


