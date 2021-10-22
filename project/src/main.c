#include "main.h"
#include "utils.h"
#include "write_funcs.h"
#include "upd_funcs.h"
#include "test.h"

#include <stdio.h>

#define CASE_INPUT_CLIENT       1
#define CASE_INPUT_TRANSACTION  2
#define CASE_UPD_BASE           3

int main() {
    int choice = 0;
    FILE *p_record = NULL;
    FILE *p_transaction = NULL;
    FILE *p_blackrecord = NULL;
    Data data_record = {0};
    Data data_transaction = {0};
    printf("\n%s\n%s\n%s\n%s\n%s\n", "Actions", "1 Enter client data",
            "2 Enter transaction data", "3 Update base", "Enter action:");
    while (scanf("%d", &choice) != -1) {
        switch (choice) {
            case CASE_INPUT_CLIENT: {
                p_record = fopen(filename_record, "w+");
                if (p_record == NULL) {
                    puts("No access\n");
                } else {
                    record_write(p_record, data_record);
                    fclose(p_record);
                }
                break;
            }
            case CASE_INPUT_TRANSACTION: {
                p_record = fopen(filename_transaction, "w+");
                if (p_record == NULL) {
                    puts("No access\n");
                } else {
                    transaction_write(p_record, data_transaction);
                    fclose(p_record);
                }
                break;
            }
            case CASE_UPD_BASE: {
                p_record = fopen(filename_record, "r");
                p_transaction = fopen(filename_transaction, "r");
                p_blackrecord = fopen(filename_blackrecord, "w");
                if ((p_record == NULL) || (p_transaction == NULL) || (p_blackrecord == NULL)) {
                    puts("No access\nexit\n");
                } else {
                    upd_base(p_record, p_transaction, p_blackrecord, data_record, data_transaction);
                    fclose(p_record);
                    fclose(p_transaction);
                    fclose(p_blackrecord);
                }
                break;
            }
            default: {
                puts("Unknown error\n");
                break;
            }
        }
        printf("\n%s\n%s\n%s\n%s\n%s\n", "Actions", "1 Enter client data",
                "2 Enter transaction data", "3 Update base", "Enter action:");
    }
    return 0;
}
