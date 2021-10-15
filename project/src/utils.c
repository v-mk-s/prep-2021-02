#include "utils.h"

#include <stddef.h>
#include <stdio.h>

size_t timer_from(int from) {
    if (from < 1) return (size_t) 0;  // если 0 то ничего не выводим

    size_t counter = 1;  // всегда выводится хотя бы "0 \n"

    int i = from;
    for (; i > 0; --i) {
        ++counter;
        printf("%d ", i);
    }

    // всегда выводится хотя бы "0 \n" -> без if
    printf("%d\n", 0);

    return counter;
}

// быстрое возведение в степень работает за O(log(n)) умножений
int custom_pow(int base, int power) {
    // 0^0 = 1

    // быстрое возведение в степень
	int result = 1;
	while (power) {
		if (power & 1)  // если текущая power нечетная, то true
			result *= base;

        /* на этом этапе power - четная, основание возводим в 
         * квадрат и сокращаем количество умножений в 2 раза
         * base^power = (base*base)^(power/2)
         * */
        base *= base;
		power >>= 1;  // power/2
	}

    return result;
}

