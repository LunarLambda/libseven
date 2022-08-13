# Game Boy Advance — Official BIOS Behaviours

Based on disassembly of legally dumped BIOS binary with SHA256
`fd2547724b505f487e6dcb29ec2ecff3af35a841a77ab2e85fd87350abd36570`.

## SoftReset

- Entry Address Flag loaded from 0x03FF\_FFFA
- Stack Initialization
    - `sp_svc` = 0x0300\_7FE0 (64 bytes down)
    - `sp_irq` = 0x0300\_7FA0 (160 bytes down)
    - `sp_sys` = 0x0300\_7F00
    - SPSR of SVC and IRQ modes are zeroed out
    - Last 512 bytes of IWRAM are zeroed out (0x0300\_7E00 - 0x0300\_7FFF)
- CPU Set to SYS mode, `r0` - `r12` zeroed out, CPSR flags and IRQ bits zeroed out
- `r14` set to 0x0800\_0000 (ROM, Entry Address Flag == 0) or 0x0200\_0000
(EWRAM, Entry Address Flag != 0)

Note: During the clearing of IWRAM, IRQs are not masked, so resetting without
disabling the IME could cause spurious breakage

## HardReset

No noteworthy behaviour, the BIOS startup sequence with its logo and sound
is repeated. The SoftReset sequence cleans everything up before the ROM
runs. The end of the BIOS sequence also resets all registers and RAM,
except when Entry Address Flag is != 0, then EWRAM and SIO are not reset.
For a ROM cold-boot, then, there should be no observable artifact from the BIOS
startup.

On flashcarts, the current game remains mapped on Hard Reset,
making it a potential fatal-crash recovery strategy, so long as no crashing IRQs
occur in the short window before SVC 38 is dispatched.

Although, since Hard Reset leaves no artifacts, detecting a crash-by-hard-reset
may not be possible in all cases. Possible solutions may be hiding data in the
cartridge GPIO ports or leaving a marker in the save medium.

## IRQ Entry

- Save `r0`, `r1`, `r2`, `r3`, `r12`, and `r14_irq` to IRQ stack.
- `r0` = 0x0400\_0000
- Jump to address stored at 0x0300\_7FFC (mirrored at 0x03FF\_FFFC) in ARM mode
- Restore regs and return

CPSR I bit is set on IRQ entry.

## SVC Entry

CPSR I bit is set on SVC entry, when BIOS functions are dispatched in
SYS mode, the I bit from `spsr\_svc` is used. Only the LSB of the SVC number
is used, so ARM mode SVCs require the number be shifted left by 16.

`r2` is always preserved.

## FIQ Entry & Other Exceptions

- `sp_fiq` = 0x0300\_7FF0 (16 bytes down)
- Save `r12`, `lr_fiq`, `spsr_fiq`, and `cpsr` to FIQ stack.
- If byte at 0x0800\_009C is 0xA5:
    - If byte at 0x0800\_00B4 has bit 7 set:
        - Jump to 0x09FF\_C000 in ARM mode
    - Else:
        - Jump to 0x09FE\_2000
- Restore registers and return

On non-debug ROMs this is essentially an expensive nop. The undefined
instruction and abort vectors also jump to this code, so undefined instructions
are generally ignored by the GBA hardware.
