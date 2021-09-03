# libseven

`libseven` is a fully from-scratch library for GBA development, meant to
replace existing libraries like `libgba` or `libtonc`.

TODO: Coding Philosophy Blurb Here

# Implementation Status

## GBA Features

- [x] Basic Data Types & Limits
- [x] Memory
- [ ] Video
- [ ] Sound
- [x] Timers
- [x] DMA (base definitions)
- [ ] SIO
- [x] Input
- [x] IRQ (base definitions, base functions)
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

## Extra Features

- [ ] Fast string routines
- [ ] Fast copy routines
- [ ] Fast math routines

## "Maybe Some Day" Features

- [ ] Custom allocators for RAM and video resources
- [ ] Custom text engine
- [ ] Replacement for devkitARM's awful makefiles
- [ ] crt0/linker script replacement to fully ditch devkitARM

# Documentation

See the `doc` folder. Files are named after their respective headers in `inc`.

TODO: Some example projects once the library is more fleshed out.

# Build

`libseven` can be built with devkitARM or a regular arm-none-eabi GCC toolchain.
Simply run `make` and `libseven.a` will be built in the project root directory.

# Linking

Add `<path to libseven>/inc` to your include search path.\
Add `<path to libseven>` to your library search path.\
Add `-lseven` to your linker flags.

TODO: devkitARM Makefile example.

# Contributing

Bug reports and pull requests are welcome! Feature requests are too but I make
zero guarantees of anything being implemented.

If you send a PR please try to follow the coding style of the project.\
If you don't I'll either nitpick at you or fix it myself and be grumpy about it.

TODO: Coding style documentation. Possibly do clang-format.

# License

This project is licensed under the Mozilla Public License Version 2.0.
See [LICENSE.txt](./LICENSE.txt) for more information.
