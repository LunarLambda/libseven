.macro func name:req code:req section=.text
    .section    \section\().\name,"ax",%progbits
    .global     \name
    .type       \name STT_FUNC
    .ifc        \code,arm
        .arm
        .align  2
    .else
        .thumb_func
        .align  1
    .endif
    .macro      endf
        .size   \name,.-\name
        .previous
        .purgem endf
    .endm
    \name\():
.endm

.macro data name:req rw:req section
    .ifc                \rw,rw
        .ifb            \section
            .section    .data.\name,"aw",%progbits
        .else
            .section    \section\().\name,"aw",%progbits
        .endif
    .else
        .ifb            \section
            .section    .rdata.\name,"a",%progbits
        .else
            .section    \section\().\name,"a",%progbits
        .endif
    .endif
    .global             \name
    .type               \name STT_OBJECT
    .macro              endd
        .size           \name,.-\name
        .previous
        .purgem         endd
    .endm
    \name\():
.endm

@ vim:ft=armv4 et sta sw=4 sts=8
