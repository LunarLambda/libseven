CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

SOURCES = \
	src/svc.s \
	src/irq.s \
	src/input.c \
	src/timer.c \
	src/dma.s \
	src/log.c \
	src/mem.s \
	src/str.s \
	src/lcd.s

INCLUDES = \
	inc \
	src

CFLAGS = \
	-Os \
	-g \
	-ffunction-sections \
	-fdata-sections \
	-ffreestanding \
	-std=c99 \
	-Wall \
	-Wpedantic \
	-mcpu=arm7tdmi \
	-mthumb -mthumb-interwork \
	$(INCLUDES:%=-I%)

BUILD = build

TARGET = libseven.a

#
# You don't need to touch anything below this point!
#

OBJECTS = $(patsubst %,$(BUILD)/obj/%.o,$(SOURCES))
DEPENDS = $(patsubst %,$(BUILD)/dep/%.d,$(SOURCES))
OBJDIRS = $(dir $(OBJECTS) $(DEPENDS))

$(BUILD)/$(TARGET): $(OBJECTS)
	@echo "AR      $@"
	@$(AR) rcs $@ $^

$(OBJECTS): | objdirs

$(BUILD)/obj/%.o: %
	@echo "COMPILE $<"
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(BUILD)/dep/$<.d $<

objdirs:
	@mkdir -p $(OBJDIRS)

clean:
	@echo "CLEAN   $(BUILD)"
	@rm -rf $(BUILD)

.PHONY: objdirs clean

-include $(DEPENDS)
