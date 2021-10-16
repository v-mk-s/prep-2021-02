// Модуль должен содержать рекурсивную функцию, которая выводит через
// пробел все целые числа от 1 до **n**, где **n** - параметр функции
#include "print_recursion.h"

#include <stddef.h>
#include <stdio.h>

void serial_number_print_to(int to) {
    if (to != 1) {
        if (to > 1) {
            serial_number_print_to(to-1);
        } else {
            serial_number_print_to(to+1);
        }
        printf(" %d", to);
    } else {
        printf("%d", to);
    }
}

