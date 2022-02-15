@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.macro fn .name:req .code .linkage=global .section
    @ Setup
    .ifndef .L__FN__
        .set .L__FN__, 0
    .endif

    @ Code type and section (only on parent function)
    .ifeq .L__FN__
        .ifc \.code,arm
            .ifnb \.section
                .section \.section,"ax",%progbits
            .else
                @ Default to .iwram.<fn> for ARM
                .section .iwram.\.name,"ax",%progbits
            .endif
            .align 2
            .arm
        .else
            .ifc \.code,thumb
                .ifnb \.section
                    .section \.section,"ax",%progbits
                .else
                    @ Default to .text.<fn> for THUMB
                    .section .text.\.name,"ax",%progbits
                .endif
                .align 1
                .thumb_func
            .else
                .error "please specify function \.name as `arm` or `thumb` code"
            .endif
        .endif
    .endif

    @ Symbol visibility
    .ifc \.linkage,global
        .global \.name
    .else
        .ifc \.linkage,local
            .local \.name
        .else
            .error "please specify function \.name as `local` or `global` linkage"
        .endif
    .endif

    @ Symbol type
    .type \.name STT_FUNC

    @ !!!
    .altmacro
    @ End function to set symbol size on `endfn`
    .macro __mkendfn n=%.L__FN__
        .macro __endfn\n
            .size \.name,.-\.name
            .purgem __endfn\n
        .endm
        .purgem __mkendfn
    .endm
    .noaltmacro

    __mkendfn

    @ Increase nested function counter
    .set .L__FN__, .L__FN__ + 1

    @ Create label
    \.name :
.endm

.macro endfn
    @ !!!
    .altmacro
    .macro __endfn from=0 to=.L__FN__
        .if \to-\from
            __endfn\from
            __endfn %(\from+1)
        .endif
    .endm

    __endfn
    .purgem __endfn
    .noaltmacro

    @ Reset nested function counter
    .set .L__FN__, 0
    .pool
    .previous
.endm

@ Declares read-writable data.
.macro data .name:req .linkage=local .section .align
    .macro              endd
        .size           \.name,.-\.name
        .previous
        .purgem         endd
    .endm

    .ifc \.linkage,global
        .global \.name
    .else
        .ifc \.linkage,local
            .local \.name
        .else
            .error "please specify linkage of \.name `local` or `global`"
        .endif
    .endif

    .ifnb \.section
        .section        \.section,"aw",%progbits
    .else
        .section        .data.\.name,"aw",%progbits
    .endif

    .ifnb \.align
        .align          \.align
    .endif

    .type               \.name STT_OBJECT
    \.name :
.endm

@ Declares read-only data.
.macro rodata .name:req .linkage=local .section .align
    .macro              endr
        .size           \.name,.-\.name
        .previous
        .purgem         endr
    .endm

    .ifc \.linkage,global
        .global \.name
    .else
        .ifc \.linkage,local
            .local \.name
        .else
            .error "please specify linkage of \.name `local` or `global`"
        .endif
    .endif

    .ifnb \.section
        .section        \.section,"a",%progbits
    .else
        .section        .rodata.\.name,"a",%progbits
    .endif

    .ifnb \.align
        .align          \.align
    .endif

    .type               \.name STT_OBJECT
    \.name :
.endm

@ Declares zero-initialized data.
.macro bss .name:req .linkage=local .section .align
    .macro              endb
        .size           \.name,.-\.name
        .previous
        .purgem         endb
    .endm

    .ifc \.linkage,global
        .global \.name
    .else
        .ifc \.linkage,local
            .local \.name
        .else
            .error "please specify linkage of \.name `local` or `global`"
        .endif
    .endif

    .ifnb \.section
        .section        \.section,"aw",%nobits
    .else
        .section        .bss.\.name,"aw",%nobits
    .endif

    .ifnb \.align
        .align          \.align
    .endif

    .type               \.name STT_OBJECT
    \.name :
.endm

@ vim: ft=armv4 et sta sw=4 sts=8
