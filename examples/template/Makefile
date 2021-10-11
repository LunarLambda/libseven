.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
	$(error "Please set DEVKITARM in your environment.")
endif

#
# Change these to match your project!
#

# Path to libseven's source directory.
LIBSEVEN := $(CURDIR)/../../

# The name of your project
TARGET   := template

# All of the source files used by your project
SOURCES  := \
	    src/main.c

# The include directories used by your project
INCLUDES := include

# The libraries used by your project
LIBS     :=

# The build directory used for your project
BUILD    := build

# Compiler, Assembler, and Linker flags
CFLAGS   := -g -O2 -std=c99 -ffunction-sections -fdata-sections
ASFLAGS  := -g
LDFLAGS  := -Wl,--gc-sections

#
# You don't need to edit anything below this point!
#

# Build files
OBJECTS = $(patsubst %,$(BUILD)/obj/%.o,$(SOURCES))
DEPENDS = $(patsubst %,$(BUILD)/dep/%.d,$(SOURCES))
OBJDIRS = $(dir $(OBJECTS) $(DEPENDS))

CFLAGS  += \
	   -mcpu=arm7tdmi \
	   -mthumb \
	   -mthumb-interwork \
	   $(INCLUDES:%=-I%)

LDFLAGS += \
	   -Wl,-Map,$(BUILD)/$(TARGET).map \
	   $(LIBS:%=-l%)

ifneq ($(strip $(LIBSEVEN)),)
	CFLAGS  += -I$(LIBSEVEN)/inc
	LDFLAGS += -L$(LIBSEVEN)/build -lseven
	MAKE_LIBSEVEN := libseven
endif

$(BUILD)/$(TARGET).gba: $(BUILD)/$(TARGET).elf
$(BUILD)/$(TARGET).elf: $(OBJECTS) | $(MAKE_LIBSEVEN)

$(OBJECTS): | objdirs

$(BUILD)/obj/%.o: %
	@echo "COMPILE $<"
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(BUILD)/dep/$<.d $<

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
	@echo "CLEAN   $(BUILD)"
	@rm -rf $(BUILD)

.PHONY: libseven objdirs clean

-include $(DEPENDS)
include $(DEVKITARM)/base_tools
