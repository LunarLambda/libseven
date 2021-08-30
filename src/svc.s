.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.macro simple_svc name:req num:req noreturn
    func \name thumb
        svc     #\num
        .ifb \noreturn
            bx  lr
        .endif
    endf
.endm

simple_svc svcSoftReset                   0 noreturn
simple_svc svcRegisterRamReset            1
simple_svc svcHalt                        2
simple_svc svcStop                        3
simple_svc svcIntrWait                    4
simple_svc svcVBlankIntrWait              5
simple_svc svcSqrt                        8
simple_svc svcArcTan                      9
simple_svc svcArcTan2                    10
simple_svc svcCpuSet                     11
simple_svc svcCpuFastSet                 12
simple_svc svcBiosChecksum               13
simple_svc svcBgAffineSet                14
simple_svc svcObjAffineSet               15
simple_svc svcBitUnPack                  16
simple_svc svcLZ77UnCompWram             17
simple_svc svcLZ77UnCompVram             18
simple_svc svcHuffUnComp                 19
simple_svc svcRLUnCompWram               20
simple_svc svcRLUnCompVram               21
simple_svc svcDiff8bitUnFilterWram       22
simple_svc svcDiff8bitUnFilterVram       23
simple_svc svcDiff16bitUnFilter          24
simple_svc svcSoundBiasChange            25
simple_svc svcSoundDriverInit            26
simple_svc svcSoundDriverMode            27
simple_svc svcSoundDriverMain            28
simple_svc svcSoundDriverVSync           29
simple_svc svcSoundChannelClear          30
simple_svc svcMidiKey2Freq               31
simple_svc svcMusicPlayerOpen            32
simple_svc svcMusicPlayerStart           33
simple_svc svcMusicPlayerStop            34
simple_svc svcMusicPlayerContinue        35
simple_svc svcMusicPlayerFadeOut         36
simple_svc svcMultiBoot                  37
simple_svc svcHardReset                  38 noreturn
simple_svc svcSoundDriverVSyncOff        40
simple_svc svcSoundDriverVSyncOn         41

func svcSoftResetEx thumb
    ldr         r3, =#0x04000208
    movs        r2, #0
    strh        r2, [r3]
    movs        r2, #1
    movs        r1, r1
    beq         1f
    bics        r0, r2
1:
    ldr         r3, =#0x03007FFA
    strb        r1, [r3]
    subs        r3, #0xFA
    mov         sp, r3
    svc         #1
    svc         #0
endf

func svcDiv thumb
    movs        r3, r0
    movs        r0, r1
    movs        r1, r2
    svc         #6
    stmia       r3!, {r0, r1}
    bx          lr
endf

func svcCpuSetFixed thumb
    sub         sp, #8
    str         r0, [sp]
    mov         r0, sp
    movs        r3, #1
    lsls        r3, r3, #24
    orrs        r2, r2, r3
    svc         #11
    add         sp, #8
    bx          lr
endf

func svcCpuFastSetFixed thumb
    sub         sp, #8
    str         r0, [sp]
    mov         r0, sp
    movs        r3, #1
    lsls        r3, r3, #24
    orrs        r2, r2, r3
    svc         #12
    add         sp, #8
    bx          lr
endf

func svcIsSystemDS thumb
    svc         #13
    ldr         r1, =#0x4551E780
    adds        r0, r0, r1
    rsbs        r1, r0, #0
    adcs        r0, r0, r1
    bx          lr
endf

@ vim:ft=armv4 et sta sw=4 sts=8
