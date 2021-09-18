# Interrupts

1. [Explanation](#explanation)
2. [Interrupt Sources](#interrupt-sources)
3. [Interrupt Registers](#interrupt-registers)
4. [The BIOS IRQ Vector](#the-bios-irq-vector)
5. [Interrupt Handlers](#interrupt-handlers)

## Explanation

Interrupt Requests (IRQs for short) are asynchronous signals sent to the CPU
by external hardware such as the
[display unit, timers, DMA engine, and more](#interrupt-sources).

When an interrupt request occurs, the CPU immediately redirects execution to
the interrupt vector in the BIOS, which does some
[minimal bookkeeping](#the-bios-irq-vector) and then transfers control to the
[interrupt service routine (ISR)](#interrupt-handlers) installed by the user.

The GBA also has a few [I/O Registers](#interrupt-registers)
that control which interrupts are handled by the CPU.

## Interrupt Sources

Interrupts can be triggered by the following events:

- Display entering V-Blank period
- Display entering H-Blank period
- Display reaching a set scanline
- A timer overflowing its counter
- Serial communication
- A DMA transfer completing
- Button or D-Pad input
- Request from the cartridge hardware (usually removal of the cartridge)

TODO: Links to other documentation explaining interrupt sources in more detail

## Interrupt Registers

The GBA has 3 important I/O registers relating to interrupt handling:

### IME

Address: 0x04000208 (Read/Write)

The IME (*"Interrupt Master Enable"*) register acts as a global switch to
enable or disable interrupts from occuring. It can only be set to 0 (disable),
or 1 (enable).

### IE

Address: 0x04000200 (Read/Write)

The IE (*"Interrupt Enable"*) register controls which interrupt sources are
allowed to trigger an interrupt.

Bit | Event
---:|:-----
  0 | Display entering V-Blank period
  1 | Display entering H-Blank period
  2 | Display reaching set scanline
  3 | Timer 0 overflowing its counter
  4 | Timer 1 overflowing its counter
  5 | Timer 2 overflowing its counter
  6 | Timer 3 overflowing its counter
  7 | Serial communication (TODO: what exactly?)
  8 | DMA 0 transfer completion
  9 | DMA 1 transfer completion
 10 | DMA 2 transfer completion
 11 | DMA 3 transfer completion
 12 | Button or D-Pad input
 13 | Interrupt request from the cartridge

Note that in addition to being enabled in the IE register, nearly all sources
require the interrupt to also be enabled in the control registers for the
respective hardware.

### IF

Address: 0x04000202 (Read/Write)

The IF (*"Interrupts Flagged"*) register shows which interrupts were requested
by the hardware. This happens regardless of which, if any, interrupts are
enabled.

Flagged interrupts are "acknowledged" by writing the corresponding bits to the
register.
