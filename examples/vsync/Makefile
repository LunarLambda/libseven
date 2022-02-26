.SUFFIXES:

ifeq ($(strip $(DEVKITPRO)),)
	$(error "Please set DEVKITPRO in your environment.")
endif

#
# Change these to match your project!
#

# Path to libseven's source directory.
LIBSEVEN := $(CURDIR)/../../

# The name of your project
PROJECT   := example-vsync

# All of the source files used by your project
SOURCES  := src/main.c

# The include directories used by your project
INCLUDES := include

# The libraries used by your project
LIBS     := seven

# Paths to the libraries used by your project.
# Adds the include and lib directories to the proper search paths.
LIBDIRS  := $(LIBSEVEN)

# The build directory used for your project
BUILDDIR := build

# Compiler, Assembler, and Linker flags
CFLAGS   := -g3 -gdwarf-4 -O2 -std=c99 -ffunction-sections -fdata-sections
LDFLAGS  :=

#
# You don't need to edit anything below this point!
#

ROMFILE = $(BUILDDIR)/$(PROJECT).gba
ELFFILE = $(BUILDDIR)/$(PROJECT).elf
MAPFILE = $(BUILDDIR)/$(PROJECT).map

# Build files
OBJECTS = $(SOURCES:%=$(BUILDDIR)/obj/%.o)
DEPENDS = $(SOURCES:%=$(BUILDDIR)/dep/%.d)
OBJDIRS = $(dir $(OBJECTS) $(DEPENDS))

CFLAGS  += \
	   -mcpu=arm7tdmi \
	   -mabi=aapcs \
	   -mthumb \
	   $(INCLUDES:%=-I%) \
	   $(LIBDIRS:%=-I%/include) \

LDFLAGS += \
	   -Wl,-Map,$(MAPFILE) \
	   $(LIBS:%=-l%) \
	   $(LIBDIRS:%=-L%/lib) \

ifneq ($(strip $(LIBSEVEN)),)
	MAKE_LIBSEVEN := libseven
	LDFLAGS += -L$(LIBSEVEN)/build
endif

$(ROMFILE): $(ELFFILE)
$(ELFFILE): $(OBJECTS) | $(MAKE_LIBSEVEN)

$(OBJECTS): | objdirs

$(BUILDDIR)/obj/%.o: %
	@echo "COMPILE $<"
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(BUILDDIR)/dep/$<.d $<

%.gba:
	@echo "GBAFIX  $@"
	@$(OBJCOPY) -O binary $< $@
	@gbafix $@ >/dev/null

%_mb.elf:
	@echo "LINK    $@ (multiboot)"
	@$(CC) -o $@ -specs=gba_mb.specs $^ $(LDFLAGS)

%.elf:
	@echo "LINK    $@ (cartridge)"
	@$(CC) -o $@ -specs=gba.specs $^ $(LDFLAGS)

libseven:
	@echo "BUILD   $@"
	@$(MAKE) --no-print-directory -C $(LIBSEVEN) -f Makefile.dkp

objdirs:
	@mkdir -p $(OBJDIRS)

clean:
	@echo "CLEAN   $(BUILDDIR)"
	@rm -rf $(BUILDDIR)

.PHONY: libseven objdirs clean

-include $(DEPENDS)
include $(DEVKITARM)/base_tools
