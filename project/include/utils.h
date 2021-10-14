// Начнем с директив препроцессора. UTILS_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef UTILS_H
#define UTILS_H // #define это удобная директива, которая позволяет дать имя константе перед тем как программа будет скомпилирована

// содержимое заголовочного файла
#include <stddef.h>

size_t timer_from(int from);
// `power of` function
int custom_pow(int base, int power);

// Заканчиваем директивой препроцессора
#endif //UTILS_H

