// Модуль должен содержать рекурсивную функцию, которая выводит через
// пробел все целые числа от 1 до **n**, где **n** - параметр функции
#include "print_numbers.h"
#include <stddef.h>
#include <stdio.h>

#define SEQUENCE_TO   1

void print_number_sequence(int to) {
    if (to == SEQUENCE_TO) {
        printf("%d", SEQUENCE_TO);
    } else {
        if (to > SEQUENCE_TO) {
            print_number_sequence(to - 1);
        } else {
            print_number_sequence(to + 1);
        }
        printf(" %d", to);
    }
}
