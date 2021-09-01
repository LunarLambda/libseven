CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

SOURCES = \
	src/svc.s \
	src/irq.s \
	src/input.c


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

OBJECTS = $(patsubst %,$(BUILD)/%.o,$(basename $(SOURCES)))
OBJDIRS = $(dir $(OBJECTS))
DEPENDS = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	@echo creating $@
	@$(AR) rcs $@ $^

$(OBJECTS): | objdirs

$(BUILD)/%.o: %.c
	@echo $<
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(@:.o=.d) $<

$(BUILD)/%.o: %.s
	@echo $<
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(@:.o=.d) $<

$(BUILD)/%.o: %.S
	@echo $<
	@$(CC) -c -o $@ $(CFLAGS) -MMD -MP -MF $(@:.o=.d) $<

objdirs:
	@mkdir -p $(OBJDIRS)

clean:
	@echo clean
	@rm -rf $(BUILD) $(TARGET)

.PHONY: objdirs clean

-include $(DEPENDS)
