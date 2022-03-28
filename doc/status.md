# libseven - Implementation Status

## GBA Hardware

- [x] DMA
- [x] IRQ
- [x] Input
- [ ] SIO
- [ ] Sound
- [x] SRAM
- [x] Timers
- [x] Video
- [x] BIOS Calls
    - [x] Reset
    - [x] Halt and IRQ Waiting
    - [x] Math
    - [x] Memory Copy
    - [x] BIOS Checksum & Checksum-based DS detection
    - [x] AffineSet
    - [x] Decompression
    - [ ] Sound/MP2000
    - [ ] Multiboot

## Utility APIs

- [x] Bit manipulation helpers, including named bitfields
- [x] Logging (mGBA, no$gba, VBA, Custom)
- [x] Fast PRNG (Xoshiro128++)
- [x] Basic profiler routine
- [ ] Fixed point helpers
- [ ] Fast string routines
- [ ] Fast memory routines
- [ ] Fast math routines

## Toolchain Features

- [x] -ffreestanding support
- [x] --gc-sections support
- [x] RAM section support
- [ ] RAM overlay support
- [ ] LTO support (needs testing)
