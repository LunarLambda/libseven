# seven\_svc.h

[Link to header](../inc/seven_svc.h)

## Synopsis

This header provides the definitions for all functions provided by the GBA
BIOS, also known as SWIs (Software Interrupts) or SVCs (Supervisor Calls).

1. [SoftReset](#svcsoftreset)
2. [SoftResetEx](#svcsoftresetex)

## Functions

### svcSoftReset

#### SVC Number

\#0 (THUMB), \#0 (ARM)

#### C Synopsis

```c
void NORETURN svcSoftReset(void);
```

#### Description

Soft-resets the console. This resets the stack pointers to their initial values.
The entry point (EWRAM or ROM) is chosen based
on the value in MULTIBOOT\_FLAG (TODO: document this better)

### svcSoftResetEx

#### SVC Number

N/A

#### C Synopsis

```c
enum SoftResetExFlags
{
    SRE_FROM_ROM = 0,
    SRE_FROM_RAM = 1,
};

void NORETURN svcSoftResetEx(u32 reset_flags, bool from_ewram);
```

Combines the functionality of [svcRegisterRamReset] and [svcSoftReset] to
perform a "clean" soft-reset. The `reset_flags` parameter is the same as
used by [svcRegisterRamReset], and the `from_ewram` parameter determine
if execution starts in EWRAM or ROM. If EWRAM is chosen, the `RRR_EWRAM`
flag is automatically cleared, such that using `RRR_EVERYTHING` is safe.
Additionally, the `IME` register is set to 0, to avoid the IRQ handler jumping
into zeroed-out memory.

#### Description
