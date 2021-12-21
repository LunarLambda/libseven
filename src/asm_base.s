@ Declares a function.
@
@ THUMB Code (ROM):
@       fn MyFunction thumb [local]
@
@ ARM Code (IWRAM):
@       fn MyFunction arm [local]
@
@ fn add thumb
@     adds      r0, r0, r1
@     bx        lr
@ endfn
@
.macro fn name:req code:req local
    .macro      endfn
        .size   \name,.-\name
        \name\()_pool:
        .pool
        .previous
        .purgem endfn
    .endm

    .ifnc               \local,local
        .global         \name
    .endif

    .type               \name STT_FUNC

    .ifc                \code,arm
        .section        .iwram.\name,"ax",%progbits
        .align          2
        .arm
    .else
        .section        .text.\name,"ax",%progbits
        .align          1
        .thumb_func
    .endif

    \name\():
.endm

@ Declares a function inside another function.
@
@ Inherits section and code type from a previous `fn`.
@
@ Doesn't support nesting due to lack of a macro stack.
@
.macro sfn name:req local
    .macro      endsfn
        .size   \name,.-\name
        .purgem endsfn
    .endm

    .ifnc       \local,local
        .global \name
    .endif

    .type       \name STT_FUNC

    \name\():
.endm

@ Declares read-writable data.
.macro data name:req
    .macro              endd
        .size           \name,.-\name
        .previous
        .purgem         endd
    .endm

    .section            .data.\name,"aw",%progbits
    .type               \name STT_OBJECT
    \name\():
.endm

@ Declares read-only data.
.macro rdata name:req
    .macro              endr
        .size           \name,.-\name
        .previous
        .purgem         endr
    .endm

    .section            .rdata.\name,"a",%progbits
    .type               \name STT_OBJECT
    \name\():
.endm

@ Declares zero-initialized data.
.macro bss name:req
    .macro              endb
        .size           \name,.-\name
        .previous
        .purgem         endb
    .endm

    .section            .bss.\name,"aw",%nobits
    .type               \name STT_OBJECT
.endm

@ vim:ft=armv4 et sta sw=4 sts=8
