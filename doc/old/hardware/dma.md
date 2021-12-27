# DMA

Direct Memory Access, or DMA for short, is a special type of memory transfer
that allows hardware other than the CPU to directly modify the main memory of
the machine.

The GBA has 4 DMA channels, numbered 0 through 3, with 0 having the highest
[priority][#channel-priority], and 3 the lowest. The different channels
also have slight differences in [what they can do][#channel-capabilities].

The engines are configured and started via the use of
[I/O registers][#dma-registers].

While DMA is very useful for some things like graphical effects and sound,
and is in some cases the fastest way to transfer memory, it's no silver bullet.
In fact, it has a handful of strange [pitfalls][#dma-pitfalls] to watch out for.

## DMA Registers

TODO

---

## Channel Priority

TODO

---

## Channel Capabilities

TODO

---

## DMA Pitfalls

TODO
