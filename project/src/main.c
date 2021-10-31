#include "prime.h"
#include "print_numbers.h"
#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_STRTOL    (-3)

typedef enum {
    CASE_TIMER_FROM_FUNC =      1,
    CASE_CUSTOM_POW_FUNC =      2,
    CASE_CUSTOM_PRIME_FUNC =    3,
    CASE_NUMBER_SEQUENCE_FUNC = 4
} Case_main;

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    // заменил atoi на strtol, повысил безопасность кода
    char* err_argv_1 = NULL;
    int test_case = (int) strtol(argv[1], &err_argv_1, 0);
    if (*err_argv_1 != '\0') {
        return ERR_STRTOL;
    }

    const char* data = argv[2];

    switch (test_case) {
        case CASE_TIMER_FROM_FUNC: {
            char* err_data_case_timer = NULL;
            int to = (int) strtol(data, &err_data_case_timer, 0);
            if (*err_data_case_timer != '\0') {
                return ERR_STRTOL;
            }
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);

            break;
        }
        case CASE_CUSTOM_POW_FUNC: {
            if (argc == 4) {
                char* err_data_case_pow = NULL;
                int base = (int) strtol(data, &err_data_case_pow, 0);
                if (*err_data_case_pow != '\0') {
                    return ERR_STRTOL;
                }

                char* err_argv_3_case_pow = NULL;
                int pow = (int) strtol(argv[3], &err_argv_3_case_pow, 0);
                if (*err_argv_3_case_pow != '\0') {
                    return ERR_STRTOL;
                }

                double res = custom_pow(base, pow);

                if (pow >= 0) {
                    printf("%d\n", (int)res);
                } else {
                    printf("%lf\n", res);
                }
            } else {
                return ERR_ARGS_COUNT;
            }

            break;
        }
        case CASE_CUSTOM_PRIME_FUNC: {
            char* err_data_case_prime = NULL;
            int num = (int) strtol(data, &err_data_case_prime, 0);
            if (*err_data_case_prime != '\0') {
                return ERR_STRTOL;
            }

            printf("%d\n", custom_prime(num));

            break;
        }
        case CASE_NUMBER_SEQUENCE_FUNC: {
            char* err_data_case_sequence = NULL;
            int num = (int) strtol(data, &err_data_case_sequence, 0);
            if (*err_data_case_sequence != '\0') {
                return ERR_STRTOL;
            }

            print_number_sequence(num);

            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}

