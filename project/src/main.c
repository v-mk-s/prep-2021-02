#include "utils.h"
#include "prime.h"
#include "print_recursion.h"

#include <stddef.h>  // size_t
#include <stdio.h>  // printf()
#include <stdlib.h>  // int atoi(const char *str) и strtol

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_STRTOL    (-3)

#define TST_FOO_FIX                 1
#define TST_FOO_IMPL                2
#define TST_MOD_IMPL                3
#define TST_SERIAL_NUMBERS_FUNC     4


int main(int argc, const char** argv) {
    char* end = NULL;

    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    // заменил atoi на strtol, повысил безопасность кода
    int test_case = (int) strtol(argv[1], &end, 0);
    if (*end != '\0') {
        return ERR_STRTOL;
    }

    const char* data = argv[2];

    switch (test_case) {
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
        case TST_SERIAL_NUMBERS_FUNC: {
            end = NULL;
            int num = (int) strtol(data, &end, 0);
            if (*end != '\0') {
                return ERR_STRTOL;
            }

            serial_number_print_to(num);

            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}

