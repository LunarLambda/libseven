#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.
#

.SUFFIXES:

# Path to gba-minrt
MINRT		:= ../../subprojects/minrt

# Path to libseven
LIBSEVEN	:= ../..

# Name of your ROM
PROJECT		:= libseven-template

# Source files
SOURCES		:= $(MINRT)/src/crt0.s src/main.c

# Include directories
INCLUDES	:= $(MINRT)/src

# Library directories, with /include and /lib
LIBDIRS		:= $(MINRT) $(LIBSEVEN)

# Libraries to link
LIBS		:= seven

# All build output goes here
BUILDDIR	:= build

# C compiler flags
CFLAGS		:= -g3 -gdwarf-4 -O2 -std=c99 -ffunction-sections -fdata-sections

# Linker flags
LDFLAGS		:= -mthumb -nostartfiles \
		   -specs=nano.specs -specs=nosys.specs \
		   -Wl,-Trom.ld

# Toolchain prefix
#
# Only change this if you want to use a different compiler
TOOLCHAIN	:= arm-none-eabi

# Uncomment this if you want to use C++
#
# USE_CXX := yes

# Uncomment this if you want to use Link Time Optimization
#
# USE_LTO := yes

#
# Internal
#

CC 	:= $(TOOLCHAIN)-gcc
CXX	:= $(TOOLCHAIN)-g++
OBJCOPY	:= $(TOOLCHAIN)-objcopy
LD	:= $(if $(USE_CXX),$(CXX),$(CC))

ELFFILE	:= $(BUILDDIR)/$(PROJECT).elf
ROMFILE	:= $(BUILDDIR)/$(PROJECT).gba
MAPFILE	:= $(BUILDDIR)/$(PROJECT).map

default: $(ROMFILE)

CFLAGS += \
	  -mcpu=arm7tdmi \
	  -mabi=aapcs \
	  -mthumb \
	  $(LIBDIRS:%=-I%/include) \
	  $(INCLUDES:%=-I%) \
	  $(if $(USE_LTO),-flto,-fno-lto) \

LDFLAGS += \
	   -Wl,--gc-sections \
	   -Wl,-Map,$(MAPFILE) \
	   $(LIBDIRS:%=-L%/lib) \
	   $(LIBS:%=-l%) \
	   $(if $(USE_LTO),-flto,-fno-lto) \

OBJECTS :=
DEPENDS :=

SPACE := $(subst ,, )

eq = $(and $(findstring x$(1),x$(2)),$(findstring x$(2),x$(1)))

pathmap = $(2)$(subst $(SPACE),/,$(foreach component,$(subst /, ,$(1)),$(if $(call eq,$(component),..),__,$(component))))$(3)

obj = $(call pathmap,$(1),$(BUILDDIR)/obj/,.o)
dep = $(call pathmap,$(1),$(BUILDDIR)/dep/,.d)

define compile =
$(call obj,$(1)): $(1)
	@echo "compile $$<"
	@$$(CC) -c -o $$@ $$(CFLAGS) -MMD -MP -MF $(call dep,$(1)) $$<

OBJECTS += $(call obj,$(1))
DEPENDS += $(call dep,$(1))
endef

$(foreach source,$(SOURCES),$(eval $(call compile,$(source))))

DIRS := $(dir $(BUILDDIR) $(OBJECTS) $(DEPENDS))

$(ELFFILE): $(OBJECTS)
$(ROMFILE): $(ELFFILE)
$(OBJECTS): | dirs

%.elf:
	@echo "link    $@"
	@$(LD) -o $@ $^ $(LDFLAGS)

%.gba:
	@echo "objcopy $@"
	@$(OBJCOPY) -O binary $< $@

dirs:
	@mkdir -p $(DIRS)

clean:
	@echo "clean   $(BUILDDIR)"
	@rm -rf $(BUILDDIR)

run: $(ELFFILE)
	@mgba-qt $(ELFFILE)

.PHONY: default dirs clean run

-include $(DEPENDS)
