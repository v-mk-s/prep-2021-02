#ifndef PRIME_H
#define PRIME_H

#include <stddef.h>

// Можно было подключить <stdbool.h> и использовать _Bool, но в памяти занимает, как int, работает только приведение типов как bool
// аналог (!!a) нормировка
// поэтому будем использовать size_t
size_t custom_prime(long long num);

#endif //PRIME_H

