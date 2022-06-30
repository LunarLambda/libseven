#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.
#

CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

PROJECT = seven

SOURCES = \
	src/hw/dma.s \
	src/hw/input.s \
	src/hw/irq.s \
	src/hw/sram.s \
	src/hw/svc.s \
	src/hw/timer.s \
	src/util/debug.s \
	src/util/log.c \
	src/util/mem.s \
	src/util/profile.s \
	src/util/rand.s \
	src/util/simd.s \
	src/util/str.s \
	src/video/bmp.s \
	src/video/oam.s \

INCLUDES = \
	src \
	include

CFLAGS = \
	-Os \
	-g3 -gdwarf-4 \
	-ffunction-sections \
	-fdata-sections \
	-ffreestanding \
	-std=c99 \
	-Wall \
	-Wpedantic \
	-mabi=aapcs \
	-mcpu=arm7tdmi \
	-mthumb \
	$(INCLUDES:%=-I%) \
	$(INCLUDES:%=-Wa,-I%)

BUILD = build
LIB   = lib


#
# You don't need to touch anything below this point!
#

TARGET  = $(LIB)/lib$(PROJECT).a

OBJECTS = $(SOURCES:%=$(BUILD)/obj/%.o)
DEPENDS = $(SOURCES:%=$(BUILD)/dep/%.d)
OBJDIRS = $(dir $(OBJECTS) $(DEPENDS))

$(TARGET): $(OBJECTS)
	@echo "$@"
	@$(AR) rcs $@ $^

$(OBJECTS): | builddirs

$(BUILD)/obj/%.o: %
	@echo "$<"
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(BUILD)/dep/$<.d $<

builddirs:
	@mkdir -p $(OBJDIRS) $(LIB)

clean:
	@echo "clean: $(BUILD) $(LIB)"
	@rm -rf $(BUILD) $(LIB)

install: $(TARGET)
	@echo "install: $(DESTDIR)$(DEVKITPRO)"
	@mkdir -p $(DESTDIR)$(DEVKITPRO)/libseven/
	@cp -r include $(DESTDIR)$(DEVKITPRO)/libseven/
	@cp -r lib $(DESTDIR)$(DEVKITPRO)/libseven/

.PHONY: builddirs clean install

-include $(DEPENDS)
