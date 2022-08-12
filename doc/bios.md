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

## IRQ Entry

## SVC Entry

## FIQ Entry & Other Exceptions
