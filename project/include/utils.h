// Начнем с директив препроцессора. UTILS_H – это произвольное уникальное имя
// (обычно используется имя заголовочного файла)
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_  // #define это удобная директива, которая позволяет дать
                                  // имя константе перед тем как программа будет скомпилирована

// содержимое заголовочного файла
#include <stddef.h>

size_t timer_from(int from);
// `power of` function
int custom_pow(int base, int power);

// Заканчиваем директивой препроцессора
#endif  // PROJECT_INCLUDE_UTILS_H_

