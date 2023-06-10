#include <stdio.h>
#include "calculation.h"

int main() {
    int a = 10, b = 5;
    int result_add = add(a, b);
    int result_subtract = subtract(a, b);

    printf("Addition: %d\n", result_add);
    printf("Subtraction: %d\n", result_subtract);

    return 0;
}
