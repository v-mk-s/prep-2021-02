// Модуль должен содержать функцию, определяющую является ли число,
// поданное на вход, простым: если да - вернуть 1, иначе 0.
#include "prime.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

bool custom_prime(int num) {
    if (num < 2) {
        return 0;
    }

    int divisor = 2;
    while ((divisor * divisor <= num) && (num % divisor != 0)) {
        ++divisor;
    }

    if (divisor * divisor <= num) {
        return 0;
    }
    return 1;
}
