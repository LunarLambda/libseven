# libseven - Implementation Status

## GBA Hardware

- [x] DMA
- [x] IRQ
- [x] Input
- [ ] SIO
    - [x] Normal mode
    - [ ] UART mode
    - [ ] Multiplayer mode
    - [ ] Raw mode
    - [ ] JOY Bus mode
- [ ] Sound
- [x] SRAM
- [x] Timers
- [x] Video
    - [x] Control and Status Registers
    - [x] Affine Backgrounds
    - [x] Bitmap Backgrounds
    - [x] Regular Backgrounds
    - [x] Blending Effects
    - [x] Colors
    - [x] Affine Matrices
    - [x] Mosaic Effects
    - [x] OAM Management
    - [x] Objects
    - [ ] Pallete Management
    - [x] Scrolling Effects
    - [x] Windowing Effects
- [x] BIOS Calls
    - [x] Reset
    - [x] IRQ Waiting
    - [x] Math
    - [x] Memory Copy
    - [x] BIOS Checksum
    - [x] Affine Functions
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
