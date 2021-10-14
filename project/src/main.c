// исключение повторного объявления библиотек
// #ifndef STDDEF_H
// #define STDDEF_H
// #include <stddef.h>
// #endif/* STDDEF_H */
#include "utils.h"
#include "prime.h"
#include "print_recursion.h"

#include <stddef.h>  // size_t
#include <stdio.h>  // printf()
#include <stdlib.h>  // int atoi(const char *str)



#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_STRTOL    (-3)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_MOD_4       4


// !! - означает заменить в след коммите
// atoi -> strtol see: https://en.cppreference.com/w/cpp/string/byte/strtol

/* NOTE(stitaevskiy):
 * We use `atoi` function just for simplification and code reducing.
 * This function doesn't report conversation errors.
 * For safety program we recommend using `strtol` and its analogs.
 * (See `man atoi` and `man strtol` for more info).
 *
 * const char str_num[] = "1234";
 * char* end = NULL;
 * int val = (int) strtol(str_num, &end, 0);
 * if (end != '\0') {
 *     //ERROR
 * }
 *
 * */

int main(int argc, const char** argv) {
    char* end = NULL;

    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    int Test_case = (int) strtol(argv[1], &end, 0);
    if (*end != '\0') {
        // printf ("%s \n", "ERROR_STRTOL");
        return ERR_STRTOL;
    }

    const char* data;
    data = argv[2];

    switch (Test_case) {
        case TST_FOO_FIX: {
            end = NULL;
            int to = (int) strtol(data, &end, 0);
            if (*end != '\0') {
                return ERR_STRTOL;
            }
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);

            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                end = NULL;
                int base = (int) strtol(data, &end, 0);
                if (*end != '\0') {
                    return ERR_STRTOL;
                }

                end = NULL;
                int pow = (int) strtol(argv[3], &end, 0);
                if (*end != '\0') {
                    return ERR_STRTOL;
                }

                int res = custom_pow(base, pow);

                printf("%i\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }

            break;
        }
        case TST_MOD_IMPL: {
            end = NULL;
            int num = (int) strtol(data, &end, 0);
            if (*end != '\0') {
                return ERR_STRTOL;
            }

            printf("%zu\n", custom_prime(num));

            break;
        }

        case TST_MOD_4: {
            end = NULL;
            int num = (int) strtol(data, &end, 0);
            if (*end != '\0') {
                return ERR_STRTOL;
            }

            // !! можно сделать возврат значения -1 если что-то
            // пошло не так из функции print_recursion
            print_recursion(num);

            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
