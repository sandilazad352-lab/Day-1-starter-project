static void semihost_write0(const char *message) {
    register int operation asm("r0") = 0x04;      /* SYS_WRITE0 */
    register const char *argument asm("r1") = message;

    asm volatile (
        "bkpt 0xAB"
        :
        : "r" (operation), "r" (argument)
        : "memory"
    );
}

int main(void) {
    semihost_write0("Hello Embedded C from QEMU Cortex-M3!\n");
    semihost_write0("Day 1 firmware run OK.\n");

    while (1) {
        /* Firmware normally never returns. */
    }

    return 0;
}
