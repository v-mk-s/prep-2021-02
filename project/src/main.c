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
    CASE_TIMER_FROM_FUNC = 1,
    CASE_CUSTOM_POW_FUNC,
    CASE_CUSTOM_PRIME_FUNC,
    CASE_NUMBER_SEQUENCE_FUNC
} case_main;

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    // заменил atoi на strtol, повысил безопасность кода
    char *test_case_end = NULL;
    int test_case = (int) strtol(argv[1], &test_case_end, 0);
    if (*test_case_end != '\0')
    {
        return ERR_STRTOL;
    }

    const char* data = argv[2];

    switch (test_case) {
        case CASE_TIMER_FROM_FUNC: {
            char* to_end = NULL;
            int to = (int) strtol(data, &to_end, 0);
            if (to_end != '\0') {
                return ERR_STRTOL;
            }
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);

            break;
        }
        case CASE_CUSTOM_POW_FUNC: {
            if (argc == 4) {
                char* base_end = NULL;
                int base = (int) strtol(data, &base_end, 0);
                if (*base_end != '\0') {
                    return ERR_STRTOL;
                }

                char* pow_end = NULL;
                int pow = (int) strtol(argv[3], &pow_end, 0);
                if (*pow_end != '\0') {
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
            char* data_case_prime_end = NULL;
            int num = (int) strtol(data, &data_case_prime_end, 0);
            if (*data_case_prime_end != '\0') {
                return ERR_STRTOL;
            }

            printf("%d\n", custom_prime(num));

            break;
        }
        case CASE_NUMBER_SEQUENCE_FUNC: {
            char* data_case_sequence_end = NULL;
            int num = (int) strtol(data, &data_case_sequence_end, 0);
            if (*data_case_sequence_end != '\0') {
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
