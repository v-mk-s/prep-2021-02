#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

size_t timer_from(int from) {
    if (from < 1) {
        return 0;
    }

    size_t counter = 1;
    for (int i = from; i > 0; --i) {
        ++counter;
        printf("%d ", i);
    }
    puts("0");

    return counter;
}

// быстрое возведение в степень работает за O(log(n)) умножений
double custom_pow(int base, int power) {
    bool negative_power = 0;
    if (power < 0) {
        power = -power;
        negative_power = 1;
    }

    int result = 1;
    while (power) {
        if (power & 1) {
            result *= base;
        }

        base *= base;
        power >>= 1;
    }

    if (negative_power) {
        return 1.0/result;
    }
    return result;
}
