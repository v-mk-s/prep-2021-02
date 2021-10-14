#include "utils.h"

#include <stddef.h>
#include <stdio.h>

size_t timer_from(int from) {
    if (from < 1) return (size_t) 0; // если 0 то ничего не выводим 

    size_t counter = 1; // всегда выводится хотя бы "0 \n"

    int i = from;
    for (; i > 0; --i) {
        ++counter;
        printf("%d ", i);
    }
    
    // всегда выводится хотя бы "0 \n" -> без if
    printf("%d\n", 0);

    return counter;
}

int custom_pow(int base, int power) {
    // 0^0 = 1
    // (-n)^k

    // быстрое возведение в степень
	int res = 1;
	while (power) {
		if (power & 1) // если нечетное -> true
			res *= base;
		base *= base;
		power >>= 1;
	}

    return res;
}
