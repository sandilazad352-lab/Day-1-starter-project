# Embedded C Day 1 Starter

এই repo-তে Day 1 এর জন্য দুইটি runnable path আছে:

1. `01-native-hello` - PC/host machine-এ normal C program build/run.
2. `02-qemu-cortexm3` - ARM Cortex-M3 bare-metal firmware style project, QEMU + semihosting দিয়ে run.

## Required tools

- Git
- GCC for native build
- CMake
- Ninja optional but recommended
- Arm GNU Toolchain: `arm-none-eabi-gcc`
- QEMU with `qemu-system-arm`

## 1) Native C run

```bash
cmake -S 01-native-hello -B build/native -G Ninja
cmake --build build/native
./build/native/day1_hello
```

Windows PowerShell/MSYS2:

```bash
./build/native/day1_hello.exe
```

## 2) QEMU Cortex-M3 firmware run

Linux/macOS/MSYS2 terminal:

```bash
cmake -S 02-qemu-cortexm3 -B build/qemu -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE=$PWD/02-qemu-cortexm3/arm-none-eabi.cmake
cmake --build build/qemu
qemu-system-arm -M lm3s6965evb -cpu cortex-m3 -nographic \
  -semihosting-config enable=on,target=native \
  -kernel build/qemu/firmware.elf
```

Expected output:

```text
Hello Embedded C from QEMU Cortex-M3!
Day 1 firmware run OK.
```

If QEMU does not exit automatically, press `Ctrl+A`, then `X`.

## Git first commit

```bash
git init
git add .
git commit -m "init: add day1 embedded c starter"
```
