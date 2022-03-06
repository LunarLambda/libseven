/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{
        .rom_header :
        {
                KEEP(*(.rom_header))
        } >LOAD_REGION

        .text :
        {
                *(.text .stub .text.* .gnu.linkonce.t.*)
                *(.gnu.warning)
                *(.glue_7t)
                *(.glue_7)
        } >LOAD_REGION

        .rodata :
        {
                *(.rodata .rodata.* .gnu.linkonce.r.*)
        } >LOAD_REGION

        /* Exception handling and unwinding */
        .ARM.extab :
        {
                *(.ARM.extab* .gnu.linkonce.armextab.*)
        } >LOAD_REGION

        .ARM.exidx :
        {
                PROVIDE_HIDDEN(__exidx_start = .);
                *(.ARM.exidx* .gnu.linkonce.armexidx.*)
                PROVIDE_HIDDEN(__exidx_end = .);
        } >LOAD_REGION

        .eh_frame_hdr :
        {
                *(.eh_frame_hdr)
                *(.eh_frame_entry .eh_frame_entry.*)
        } >LOAD_REGION

        .eh_frame :
        {
                KEEP(*(.eh_frame))
                *(.eh_frame.*)
        } >LOAD_REGION

        .gcc_except_table :
        {
                *(.gcc_except_table .gcc_ecept_table.*)
        } >LOAD_REGION

        /* Can't figure out what this does... */
        .gnu_extab :
        {
                *(.gnu_extab*)
        } >LOAD_REGION

        /* Static initialization and finalization */
        .preinit_array :
        {
                PROVIDE_HIDDEN(__preinit_array_start = .);
                KEEP(*(.preinit_array))
                PROVIDE_HIDDEN(__preinit_array_end = .);
        } >LOAD_REGION

        .init_array :
        {
                PROVIDE_HIDDEN(__init_array_start = .);
                KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
                KEEP(*(.init_array EXCLUDE_FILE(*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o) .ctors))
                PROVIDE_HIDDEN(__init_array_end = .);
        } >LOAD_REGION

        .fini_array :
        {
                PROVIDE_HIDDEN(__fini_array_start = .);
                KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
                KEEP(*(.fini_array EXCLUDE_FILE(*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o) .dtors))
                PROVIDE_HIDDEN(__fini_array_end = .);
        } >LOAD_REGION

        /* We want to make sure all of the RAM sections are word-aligned at least
         * Every subsequent section also word-aligns itself at the end
         */
        .iwram : ALIGN(4)
        {
                *(SORT(.iwram.sorted.*))
                *(.iwram .iwram.*)
                *(.data .data.* .gnu.linkonce.d.*)
                . = ALIGN(4);
        } >IWRAM AT>LOAD_REGION

        OVERLAY : NOCROSSREFS AT(__iwram_end)
        {
                .iwram0 { *(.iwram0 .iwram0.*) . = ALIGN(4); }
                .iwram1 { *(.iwram1 .iwram1.*) . = ALIGN(4); }
                .iwram2 { *(.iwram2 .iwram2.*) . = ALIGN(4); }
                .iwram3 { *(.iwram3 .iwram3.*) . = ALIGN(4); }
                .iwram4 { *(.iwram4 .iwram4.*) . = ALIGN(4); }
                .iwram5 { *(.iwram5 .iwram5.*) . = ALIGN(4); }
                .iwram6 { *(.iwram6 .iwram6.*) . = ALIGN(4); }
                .iwram7 { *(.iwram7 .iwram7.*) . = ALIGN(4); }
                .iwram8 { *(.iwram8 .iwram8.*) . = ALIGN(4); }
                .iwram9 { *(.iwram9 .iwram9.*) . = ALIGN(4); }
        } >IWRAM

        .iwram_bss (NOLOAD) :
        {
                *(.bss .bss.* .gnu.linkonce.b.*)
                *(COMMON)
                . = ALIGN(4);
        } >IWRAM

        .ewram :
        {
                *(SORT(.ewram.sorted.*))
                *(.ewram .ewram.*)
                . = ALIGN(4);
        } >EWRAM AT>LOAD_REGION

        OVERLAY : NOCROSSREFS AT(__ewram_end)
        {
                .ewram0 { *(.ewram0 .ewram0.*) . = ALIGN(4); }
                .ewram1 { *(.ewram1 .ewram1.*) . = ALIGN(4); }
                .ewram2 { *(.ewram2 .ewram2.*) . = ALIGN(4); }
                .ewram3 { *(.ewram3 .ewram3.*) . = ALIGN(4); }
                .ewram4 { *(.ewram4 .ewram4.*) . = ALIGN(4); }
                .ewram5 { *(.ewram5 .ewram5.*) . = ALIGN(4); }
                .ewram6 { *(.ewram6 .ewram6.*) . = ALIGN(4); }
                .ewram7 { *(.ewram7 .ewram7.*) . = ALIGN(4); }
                .ewram8 { *(.ewram8 .ewram8.*) . = ALIGN(4); }
                .ewram9 { *(.ewram9 .ewram9.*) . = ALIGN(4); }
        } >EWRAM

        .ewram_bss (NOLOAD) :
        {
                *(.ewram_bss .ewram_bss.* .sbss .sbss.*)
                . = ALIGN(4);
        } >EWRAM

        __iwram_vma = ADDR(.iwram);
        __iwram_lma = LOADADDR(.iwram);
        __iwram_end = LOADADDR(.iwram) + SIZEOF(.iwram);
        __iwram_dma = SIZEOF(.iwram) >> 2 | 0x84000000;

        __iwram_overlay_vma = ADDR(.iwram0);
        __iwram_overlay_dma = SIZEOF(.iwram0) >> 2 | 0x84000000;

        __iwram_bss_vma = ADDR(.iwram_bss);
        __iwram_bss_end = ADDR(.iwram_bss) + SIZEOF(.iwram_bss);
        __iwram_bss_dma = SIZEOF(.iwram_bss) >> 2 | 0x85000000;

        __iwram_size  = __iwram_bss_end - ORIGIN(IWRAM);
        __iwram_limit = LENGTH(IWRAM) - 512;

        ASSERT(__iwram_size <= __iwram_limit, "Not enough free IWRAM for stack.")

        __ewram_vma = ADDR(.ewram);
        __ewram_lma = LOADADDR(.ewram);
        __ewram_end = LOADADDR(.ewram) + SIZEOF(.ewram);
        __ewram_dma = SIZEOF(.ewram) >> 2 | 0x84000000;

        __ewram_overlay_vma = ADDR(.ewram0);
        __ewram_overlay_dma = SIZEOF(.ewram0) >> 2 | 0x84000000;

        __ewram_bss_vma = ADDR(.ewram_bss);
        __ewram_bss_end = ADDR(.ewram_bss) + SIZEOF(.ewram_bss);
        __ewram_bss_dma = SIZEOF(.ewram_bss) >> 2 | 0x85000000;

        __ewram_size = __ewram_bss_end - ORIGIN(EWRAM);

        /* Stabs debugging sections.  */
        .stab          0 : { *(.stab) }
        .stabstr       0 : { *(.stabstr) }
        .stab.excl     0 : { *(.stab.excl) }
        .stab.exclstr  0 : { *(.stab.exclstr) }
        .stab.index    0 : { *(.stab.index) }
        .stab.indexstr 0 : { *(.stab.indexstr) }
        .comment       0 : { *(.comment) }
        .gnu.build.attributes : { *(.gnu.build.attributes .gnu.build.attributes.*) }
        /* DWARF debug sections.
           Symbols in the DWARF debugging sections are relative to the beginning
           of the section so we begin them at 0.  */
        /* DWARF 1.  */
        .debug          0 : { *(.debug) }
        .line           0 : { *(.line) }
        /* GNU DWARF 1 extensions.  */
        .debug_srcinfo  0 : { *(.debug_srcinfo) }
        .debug_sfnames  0 : { *(.debug_sfnames) }
        /* DWARF 1.1 and DWARF 2.  */
        .debug_aranges  0 : { *(.debug_aranges) }
        .debug_pubnames 0 : { *(.debug_pubnames) }
        /* DWARF 2.  */
        .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
        .debug_abbrev   0 : { *(.debug_abbrev) }
        .debug_line     0 : { *(.debug_line .debug_line.* .debug_line_end) }
        .debug_frame    0 : { *(.debug_frame) }
        .debug_str      0 : { *(.debug_str) }
        .debug_loc      0 : { *(.debug_loc) }
        .debug_macinfo  0 : { *(.debug_macinfo) }
        /* SGI/MIPS DWARF 2 extensions.  */
        .debug_weaknames 0 : { *(.debug_weaknames) }
        .debug_funcnames 0 : { *(.debug_funcnames) }
        .debug_typenames 0 : { *(.debug_typenames) }
        .debug_varnames  0 : { *(.debug_varnames) }
        /* DWARF 3.  */
        .debug_pubtypes 0 : { *(.debug_pubtypes) }
        .debug_ranges   0 : { *(.debug_ranges) }
        /* DWARF 5.  */
        .debug_addr     0 : { *(.debug_addr) }
        .debug_line_str 0 : { *(.debug_line_str) }
        .debug_loclists 0 : { *(.debug_loclists) }
        .debug_macro    0 : { *(.debug_macro) }
        .debug_names    0 : { *(.debug_names) }
        .debug_rnglists 0 : { *(.debug_rnglists) }
        .debug_str_offsets 0 : { *(.debug_str_offsets) }
        .debug_sup      0 : { *(.debug_sup) }
        .ARM.attributes 0 : { KEEP (*(.ARM.attributes)) KEEP (*(.gnu.attributes)) }
        .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
        /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}
