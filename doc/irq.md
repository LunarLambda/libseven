# Interrupts

1. [Explanation](#explanation)
2. [Interrupt Sources](#interrupt-sources)
3. [Interrupt Registers](#interrupt-registers)
4. [The Interrupt Vector](#the-interrupt-vector)
5. [Interrupt Handlers](#interrupt-handlers)

---

## Explanation

Interrupt Requests (IRQs for short) are asynchronous signals sent to the CPU
by external hardware such as the
[display unit, timers, DMA engine, and more](#interrupt-sources).

When an interrupt request occurs, the CPU immediately redirects execution to
the interrupt vector in the BIOS, which does some
[minimal bookkeeping](#the-interrupt-vector) and then transfers control to the
[interrupt service routine (ISR)](#interrupt-handlers) installed by the user.

The GBA also has a few [I/O Registers](#interrupt-registers)
that control which interrupts are handled by the CPU.

---

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

TODO: Links to other documentation explaining interrupt sources in more detail.

---

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

---

## The Interrupt Vector

⚠️ This section is very technical and requires knowledge of how the CPU works.
It is not required to read this section to use interrupts on the GBA!

When an interrupt occurs, the following steps are taken by the CPU:

1. The address of the next instruction +4 is saved in the r14\_irq register.
2. The CPSR is saved to the SPSR\_irq register.
3. Interrupts are disabled in the CPSR and the mode is changed to IRQ mode.
4. Execution is transferred to the IRQ vector at address 0x00000018.

Once this has been done, the BIOS' interrupt handling code runs.
It does the following:

1. Pushes the registers r0, r1, r2, r3, r12, and r14 (lr) to the IRQ stack.
2. Calls the function stored in the RAM location at address 0x03FFFFFC.
This function *must* be an ARM function.
3. Restores the previously pushed registers.
4. Returns from the exception via the appropriate return instruction.

---

## Interrupt Handlers

Interrupt handlers, sometimes referred to as Interrupt Service Routines (ISRs),
are special functions that perform the task of discerning which interrupts
have occured, and handle them in the appropriate way, usually by calling
other functions depending on the interrupt in question.

Generally, this involves the following steps:

1. Saving any additional registers needed.
2. Determining the interrupt cause(s).
3. Acknowledging the appropriate interrupts.
4. Writing the BIOS-specific IF-like variable at address 0x03FFFFF8.
This is required for BIOS functions like [IntrWait] or [VBlankIntrWait] to work
correctly.
5. Doing the required bookkeeping to enable nested interrupts (optional).
6. Calling an appropriate handler function for the requested interrupts.
Usually this is done using a lookup table.
7. Restoring any saved registers and returning from the function.

See [Writing an Interrupt Service Routine](./irq_handler.md) (TODO!)
for detailed explanations of these steps.

See [libseven's default interrupt handler][libseven-irq] as an annotated
example of an ISR that follows these steps.

[IntrWait]: ./svc.md#intrwait
[VBlankIntrWait]: ./svc.md#vblankintrwait
[libseven-irq]: https://github.com/LunarLambda/libseven/blob/67a50a2021c8545b2dc5c753d9280a82ea73b123/src/irq.s#L11
