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

@ vim:ft=armv4 et sta sw=4 sts=8
