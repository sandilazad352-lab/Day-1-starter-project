#include <stdio.h>
#include "app.h"

int add(int a, int b) {
    return a + b;
}

int safe_divide(int a, int b, int *result) {
    if (b == 0 || result == NULL) {
        return -1;
    }

    *result = a / b;
    return 0;
}

int main(void) {
    int a = 20;
    int b = 6;
    int div_result = 0;

    printf("Hello Embedded C Day 1!\n");
    printf("a + b = %d\n", add(a, b));
    printf("a / b = %d, remainder = %d\n", a / b, a % b);

    if (safe_divide(a, b, &div_result) == 0) {
        printf("safe_divide result = %d\n", div_result);
    }

    return 0;
}
