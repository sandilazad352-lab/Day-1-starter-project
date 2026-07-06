extern int main(void);
extern unsigned long _estack;

void Reset_Handler(void);
void Default_Handler(void);

__attribute__((section(".isr_vector")))
const void *vector_table[] = {
    &_estack,
    Reset_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    0,
    0,
    0,
    0,
    Default_Handler,
    Default_Handler,
    0,
    Default_Handler,
    Default_Handler
};

void Reset_Handler(void) {
    (void)main();
    while (1) {
        /* Stop here if semihosting exit is not used. */
    }
}

void Default_Handler(void) {
    while (1) {
    }
}
