cmake_minimum_required(VERSION 3.0)

project(libseven C ASM)

add_library(seven STATIC
    src/hw/dma.s
    src/hw/input.c
    src/hw/irq.s
    src/hw/lcd.s
    src/hw/sram.s
    src/hw/svc.s
    src/hw/timer.c
    src/util/log.c
    src/util/mem.s
    src/util/profile.s
    src/util/rand.s
    src/util/str.s
)

target_include_directories(seven PUBLIC include/)
target_include_directories(seven PRIVATE src/)

if(NOT CMAKE_C_COMPILER_ID STREQUAL "Clang") # Clang does not support -mthumb-interwork
    set(flagInterwork -mthumb-interwork)
endif()

target_compile_options(seven PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-Os -g -ffunction-sections -fdata-sections -ffreestanding -std=c99 -Wall -Wpedantic -mcpu=arm7tdmi -mthumb ${flagInterwork}>
)

# Allow the string "libseven" as a parameter for target_link_libraries
add_library(libseven ALIAS seven)

if(EXISTS $ENV{DEVKITPRO})
    install(TARGETS seven DESTINATION "$ENV{DEVKITPRO}/libseven/lib")
    install(DIRECTORY include/ DESTINATION "$ENV{DEVKITPRO}/libseven/include")
    install(FILES LICENSE_SRC.txt DESTINATION "$ENV{DEVKITPRO}/libseven")
endif()
