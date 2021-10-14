#ifndef PROJECT_INCLUDE_PRIME_H_
#define PROJECT_INCLUDE_PRIME_H_

#include <stddef.h>

// Можно было подключить <stdbool.h> и использовать _Bool, но в памяти занимает,
// как int, работает только приведение типов как bool
// аналог (!!a) нормировка
// поэтому будем использовать size_t
size_t custom_prime(long long num);

#endif  // PROJECT_INCLUDE_PRIME_H_

