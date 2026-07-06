cmake_minimum_required(VERSION 3.20)
project(qemu_cortexm3_hello C ASM)

add_executable(firmware.elf
    startup.c
    src/main.c
)

target_compile_options(firmware.elf PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -ffreestanding
    -fdata-sections
    -ffunction-sections
    -Wall
    -Wextra
    -g
)

target_link_options(firmware.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker.ld
    -nostdlib
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map
)

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:firmware.elf>
)
