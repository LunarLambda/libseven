# seven\_svc.h

[Link to header](../inc/seven_svc.h)


## Synopsis

This header provides the definitions for all functions provided by the GBA
BIOS, also known as SWIs (Software Interrupts) or SVCs (Supervisor Calls).

See the [SVC FAQ](./svc_faq.md) for common questions around libseven's
implementation of these functions.

See [SVC Numbers](./svc_numbers.md) for a more compact table.


## Standard SVCs

These functions pass their arguments to the BIOS unmodified.

1. [SoftReset][svcSoftReset]
2. [RegisterRamReset][svcRegisterRamReset]
3. [Halt][svcHalt]
4. [Stop][svcStop]
5. [CpuSet][svcCpuSet]
6. [BiosChecksum][svcBiosChecksum]
7. [HardReset][svcHardReset]

## Custom SVCs

These functions are custom to libseven and mainly provide safer or more
convenient ways to use certain SVCs.

1. [SoftResetEx][svcSoftResetEx]
2. [CpuSetFixed][svcCpuSetFixed]
3. [IsSystemDS][svcIsSystemDS]

---


## svcSoftReset

### SVC Number

\#0 (THUMB), \#0 (ARM)

### C Synopsis

```c
void NORETURN svcSoftReset(void);
```

### Description

Soft-resets the console. This resets the stack pointers to their initial values.
The entry point (EWRAM or ROM) is chosen based
on the value in MULTIBOOT\_FLAG (TODO: document this better)

---


## svcSoftResetEx

### C Synopsis

```c
enum SoftResetExFlags
{
    SRE_FROM_ROM = 0,
    SRE_FROM_RAM = 1,
};

void NORETURN svcSoftResetEx(u8 reset_flags, bool from_ewram);
```

### Description

Combines the functionality of [svcRegisterRamReset] and [svcSoftReset] to
perform a "clean" soft-reset. The `reset_flags` parameter is the same as
used by [svcRegisterRamReset], and the `from_ewram` parameter determines
if execution starts in EWRAM or ROM. If EWRAM is chosen, the `RRR_EWRAM`
flag is automatically cleared, such that using `RRR_EVERYTHING` is safe.
Additionally, the `IME` register is set to 0, to avoid the IRQ handler jumping
into zeroed-out memory.

---


## svcHardReset

### SVC Number

\#38 (THUMB), \#2490368 (ARM)

### C Synopsis

```c
void NORETURN svcHardReset(void)
```

### Description

Hard-resets the console, causing the BIOS to go through the full boot process.
There's really no need to use this, unless you can find a cool way to exploit
the startup animation.

---


## svcRegisterRamReset

### SVC Number

\#1 (THUMB), \#65536 (ARM)

### C Synopsis

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

### Description

Clears the selected RAM and I/O register areas.

⚠️ Clearing OAM does not make objects invisible. Beware of graphical artifacts.\
⚠️ When clearing RAM, make sure to disable interrupts if your handler resides
there.

---


## svcHalt

### SVC Number

\#2 (THUMB), \#131072 (ARM)

### C Synopsis

```c
void svcHalt(void);
```

### Description

Pauses the CPU until an enabled interrupt is requested, that is IE & IF != 0.
This works regardless of if the CPSR I bit is set, or if the IME register is
enabled.

All other hardware is left running, and should be disabled if appropriate.

TODO: Add links to IRQ and CPU documentation

---


## svcStop

### SVC Number

\#3 (THUMB), \#196608 (ARM)

### C Synopsis

```c
void svcStop(void);
```

### Description

Pauses all hardware until one of the following interrupts occurs, if enabled:

- Keypad
- Cartridge
- Serial I/O

The IF register is not set following a return from the stop state.


---

## svcCpuSet

### SVC Number

\#11 (THUMB), \#720896 (ARM)

### C Synopsis

```c
enum CpuSetFlags
{
    CS_SRC_FIXED        = 0x1000000,
    CS_32BIT            = 0x4000000,
    CS_16BIT            = !CS_32BIT,
};

void svcCpuSet(const void *src, void *dst, u32 ctrl);
```

### Description

Copies 16-bit halfwords or 32-bit words from the source address in `src` to the
destination address in `dst`. Both addresses must be aligned to 2 or 4 bytes
respectively. `ctrl` holds the number of units to copy/set, as well as a
combination of the flags defined in `CpuSetFlags`. If `CS_SRC_FIXED` is used,
the value pointed to  by `src` is used to fill the destination instead.
See also [svcCpuSetFixed].

⚠️ The transfer count is limited to 20 bits, or 1048576 units. In practice this
limit should not cause any problems, however.

---


## svcCpuSetFixed

### C Synopsis

```c
void svcCpuSetFixed(u32 value, void *dst, u32 ctrl);
```

### Description

Wrapper around [svcCpuSet] that pushes `value` onto the stack and uses the
`CS_SRC_FIXED` flag to fill the destination memory.

---


## svcBiosChecksum

### SVC Number

\#13 (THUMB), \#851968 (ARM)

### C Synopsis

```c
u32 svcBiosChecksum(void);
```

### Description

Returns the BIOS checksum. Common return values are:

- 0xBAEE187F - Used in all models of the GBA, including the GBA
Player addon for the GameCube.
- 0xBAEE1880 - Used in all models of the DS that support GBA games, including
the 3DS family of consoles.

---


## svcIsSystemDS

### C Synopsis

```c
bool svcIsSystemDS(void);
```

### Description

Wrapper around [svcBiosChecksum] that checks if the BIOS checksum matches that
of the BIOS used in the DS family of devices.

---


[svcSoftReset]: #svcsoftreset
[svcSoftResetEx]: #svcsoftresetex
[svcRegisterRamReset]: #svcregisterramreset
[svcCpuSet]: #svccpuset
[svcCpuSetFixed]: #svccpusetfixed
[svcBiosChecksum]: #svcbioschecksum
[svcIsSystemDS]: #svcissystemds
[svcHardReset]: #svchardreset
[svcHalt]: #svchalt
[svcStop]: #svcstop