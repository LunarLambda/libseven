# libseven

`libseven` is a fully from-scratch library for GBA development, meant to
replace existing libraries like `libgba` or `libtonc`.

It has the following key goals:

- A straightforward, consistent API covering the most common tasks around GBA
programming.
- Optimize for speed where it matters.
- Optimize for size everywhere else.
- Avoid common pitfalls and strange bugs.
- Provide high-quality, accessible documentation for the GBA hardware and APIs.

# Implementation Status

## GBA Features

- [x] Basic Data Types & Limits
- [x] Memory Map
- [x] Video (Base Definitions)
- [ ] Sound
- [x] Timers
- [x] DMA
- [ ] SIO
- [x] Input
- [x] IRQ (Basic Functions)
- [x] BIOS Functions (incomplete)
    - [x] Reset
    - [x] Halt and IRQ Waiting
    - [x] Math
    - [x] Memory Copy
    - [x] BIOS Checksum & Checksum-based DS detection
    - [x] AffineSet
    - [x] Decompression
    - [ ] Sound/MP2000
    - [ ] Multiboot

## Compiler Features

- [x] GCC -ffreestanding support
- [x] GNU LD --gc-sections support
- [x] devkitARM RAM section support
- [ ] devkitARM RAM overlay support
- [ ] LTO support (needs testing)

## Extra Features

- [x] Logging (MGBA, NO$GBA, Custom)
- [x] Fast PRNG (Xoshiro128++)
- [x] Basic profiler routine
- [ ] Fast string routines
- [ ] Fast memory routines
- [ ] Fast math routines

## Other Planned Libraries and Toolchain Features

- [ ] Custom allocator library for RAM and video resources
- [ ] Custom text engine
- [ ] Savefile support library
- [ ] ROM-filesystem (GBFS replacement)
- [x] Replacement for devkitARM's awful makefiles
- [ ] crt0/linker script replacement to fully ditch devkitARM

# Documentation

See the `doc` folder. Files are named after their respective headers in `inc`.

# Build

`libseven` can be built with devkitARM or a regular arm-none-eabi GCC toolchain.
Simply run `make` and `libseven.a` will be built in the `build` directory.

Run `make -f Makefile.dkp` to use the devkitARM compiler.

# Linking

Add `<path to libseven>/inc` to your include search path.\
Add `<path to libseven>/build` to your library search path.\
Add `-lseven` to your linker flags.

You can also use the [template project](./examples/template).

# Contributing

Bug reports and pull requests are welcome! Feature requests are as well but as
of now there are zero guarantees of anything.

If you open a PR please try to follow the coding style of the project.

You can also reach out to us in the `#libseven` channel in the
[gbadev discord](https://discord.io/gbadev)

# License

All source code in this project is licensed under the
Mozilla Public License Version 2.0.\
See [LICENSE\_SRC.txt](./LICENSE\_SRC.txt) for more information.

All documentation in this project is licensed under the
CC0 1.0 Universal license.\
See [LICENSE\_DOC.txt](./LICENSE_DOC.txt) for more information.
