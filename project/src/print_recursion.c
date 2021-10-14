// Модуль должен содержать рекурсивную функцию, которая выводит через пробел все целые числа от 1 до **n**, где **n** - параметр функции
#include "print_recursion.h"

#include <stddef.h>
#include <stdio.h>

void print_recursion(int n) {
    // если не очевидна данная реализация, смотрите код ниже
    if (n != 1) {
        if (n > 1) print_recursion(n-1);
        else print_recursion(n+1);

        printf(" %d", n);
    }
    else printf("%d", n);
}

/* //понятная рекурсия
void print_recursion(int n) {
    if (n != 1) {
        if (n > 1) print_recursion(n-1);
        else print_recursion(n+1);
    }
    
    // нужно чтобы в конце не выводился лишний символ пробела
    if (n == 1) printf("%d", n);
    else printf(" %d", n);
} */


/* //не рекурсия
void print_recursion(int n) {
    if (n > 1) {
        for (int i=n; i > 1; --i)
            printf("%d ", i);
    } else {
        for (int i=n; i < 1; ++i)
            printf("%d ", i);
    }
    
    // последняя всегда 1ца, можно вынести из условия if и после нее нет пробела
    printf("%d", 1);
} */

