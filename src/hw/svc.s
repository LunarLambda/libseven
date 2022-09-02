@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/svc.s"

.macro svc_impl name:req num:req noreturn
    fn \name thumb
        svc     #\num
        .ifnc \noreturn,noreturn
            bx  lr
        .endif
    endfn
.endm

@ svc_impl svcSoftReset             0 noreturn
svc_impl svcRegisterRamReset      1
svc_impl svcHalt                  2
svc_impl svcStop                  3
svc_impl svcIntrWait              4
svc_impl svcVBlankIntrWait        5
svc_impl svcSqrt                  8
svc_impl svcArcTan                9
svc_impl svcArcTan2              10
svc_impl svcCpuSet               11
svc_impl svcCpuFastSet           12
svc_impl svcBiosChecksum         13
svc_impl svcBgAffineSet          14
svc_impl svcObjAffineSet         15
svc_impl svcBitUnPack            16
svc_impl svcLZ77UnCompWram       17
svc_impl svcLZ77UnCompVram       18
svc_impl svcHuffUnComp           19
svc_impl svcRLUnCompWram         20
svc_impl svcRLUnCompVram         21
svc_impl svcDiff8bitUnFilterWram 22
svc_impl svcDiff8bitUnFilterVram 23
svc_impl svcDiff16bitUnFilter    24
svc_impl svcSoundBiasChange      25
svc_impl svcSoundDriverInit      26
svc_impl svcSoundDriverMode      27
svc_impl svcSoundDriverMain      28
svc_impl svcSoundDriverVSync     29
svc_impl svcSoundChannelClear    30
svc_impl svcMidiKey2Freq         31
svc_impl svcMusicPlayerOpen      32
svc_impl svcMusicPlayerStart     33
svc_impl svcMusicPlayerStop      34
svc_impl svcMusicPlayerContinue  35
svc_impl svcMusicPlayerFadeOut   36
svc_impl svcMultiBoot            37
@ svc_impl svcHardReset            38 noreturn
svc_impl svcSoundDriverVSyncOff  40
svc_impl svcSoundDriverVSyncOn   41

@ We do not need to fix the stack pointer here. Even if the stacks are
@ completely trashed, since SoftReset is noreturn, and the first thing it does
@ is reset the stack pointers, it's fine even if the SVC handler couldn't
@ correctly return.
@
@ We do disable IRQs however, since during the time the BIOS clears the upper
@ 512 bytes of IWRAM, including the IRQ handler pointer, interrupts aren't
@ being masked in the CPSR.
fn svcSoftReset thumb
    ldr         r2, =0x40000208
    str         r2, [r2]
    svc         #SVC_SOFTRESET
endfn

@ Here we do fix the system mode stack pointer, since RegisterRamReset uses the
@ the stack. We assume in good faith that the SVC-mode stack pointer is fine,
@ since under any normal circumstances, including total program failure,
@ it really shouldn't be modified from it's defaults. Maybe if minrt ever
@ supports relocating the stack pointers.
fn svcSoftResetEx thumb
    ldr         r2, =0x04000208
    strh        r2, [r2]
    movs        r1, r1
    beq         1f
    movs        r2, #1
    bics        r0, r2
1:
    ldr         r2, =0x03007FFA
    strb        r1, [r2]
    subs        r2, #0xFA
    mov         sp, r2
    svc         #SVC_REGISTERRAMRESET
    svc         #SVC_SOFTRESET
endfn

fn svcHardReset thumb
    ldr         r2, =0x04000208
    str         r2, [r2]
    svc         #SVC_HARDRESET
endfn

@ extern void svcIntrWaitEx(u8 op, u16 intr_flags);
@
@ enum IntrWaitExFlags
@ {
@     IWE_WAIT_NEXT     = BIT(0),
@     IWE_CLEAR_IE      = BIT(1),
@     IEW_ADD_IE        = !IWE_CLEAR_IE,
@ }
fn svcIntrWaitEx thumb
    @ Load IE
    ldr         r3, =0x04000200
    @ if (!(op & 2 /* IWE_CLEAR */)) { intr_flags |= IE; }
    lsrs        r2, r0, #2
    ldrh        r2, [r3]
    bcs         1f
    orrs        r1, r1, r2
1:
    @ Set IE
    mov         r12, r3
    strh        r1, [r3]
    svc         #SVC_INTRWAIT
    mov         r3, r12
    @ Restore IE
    strh        r2, [r3]
    bx          lr
endfn

fn svcDiv thumb
    movs        r3, r0
    movs        r0, r1
    movs        r1, r2
    movs        r2, r3
    svc         #SVC_DIV
    stmia       r2!, {r0, r1}
    bx          lr
endfn

fn svcCpuSetFixed thumb
    sub         sp, #8
    str         r0, [sp]
    mov         r0, sp
    movs        r3, #1
    lsls        r3, r3, #24
    orrs        r2, r2, r3
    svc         #SVC_CPUSET
    add         sp, #8
    bx          lr
endfn

fn svcCpuFastSetFixed thumb
    sub         sp, #8
    str         r0, [sp]
    mov         r0, sp
    movs        r3, #1
    lsls        r3, r3, #24
    orrs        r2, r2, r3
    svc         #SVC_CPUFASTSET
    add         sp, #8
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
