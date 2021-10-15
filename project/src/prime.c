// Модуль должен содержать функцию, определяющую является ли число,
// поданное на вход, простым: если да - вернуть 1, иначе 0.
#include "prime.h"

#include <stddef.h>
#include <math.h> /* sqrt */

size_t custom_prime(long long num) {
    if (num < 2) return (size_t) 0;

	// работает за O(sqrt(n))
	for(long long i = 2; i <= sqrt(num); ++i)
		if(!num%i)
			return (size_t) 0;
	return (size_t) 1;
}

