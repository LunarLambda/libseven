# seven\_svc.h

[Link to header](../inc/seven_svc.h)

## Synopsis

This header provides the definitions for all functions provided by the GBA
BIOS, also known as SWIs (Software Interrupts) or SVCs (Supervisor Calls).

1. [SoftReset][svcSoftReset]
2. [SoftResetEx][svcSoftResetEx]
3. [RegisterRamReset][svcRegisterRamReset]

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

#### Description

Combines the functionality of [svcRegisterRamReset] and [svcSoftReset] to
perform a "clean" soft-reset. The `reset_flags` parameter is the same as
used by [svcRegisterRamReset], and the `from_ewram` parameter determines
if execution starts in EWRAM or ROM. If EWRAM is chosen, the `RRR_EWRAM`
flag is automatically cleared, such that using `RRR_EVERYTHING` is safe.
Additionally, the `IME` register is set to 0, to avoid the IRQ handler jumping
into zeroed-out memory.

### svcRegisterRamReset

#### SVC Number

\#1 (THUMB), \#65536 (ARM)

#### C Synopsis

```c
enum RegisterRamResetFlags
{
    RRR_EWRAM           = 0x01,
    RRR_IWRAM           = 0x02,
    RRR_PALETTE         = 0x04,
    RRR_VRAM            = 0x08,
    RRR_OAM             = 0x10,
    RRR_SIO             = 0x20,
    RRR_SOUND           = 0x40,
    RRR_REGISTERS       = 0x80,
    RRR_EVERYTHING      = 0xFF,
};

void svcRegisterRamReset(u8 reset_flags);
```

#### Description

Clears the selected RAM and I/O register areas.

⚠️ Clearing OAM does not make objects invisible. Beware of graphical artifacts.\
⚠️ When clearing RAM, make sure to disable interrupts if your handler resides
there.

[svcSoftReset]: #svcsoftreset
[svcSoftResetEx]: #svcsoftresetex
[svcRegisterRamReset]: #svcregisterramreset
