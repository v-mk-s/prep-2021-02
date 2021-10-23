#include "utils.h"
#include "write_to_db_funcs.h"
#include "upd_funcs.h"
#include <stdio.h>

#define CASE_INPUT_DB_CLIENTS    1
#define CASE_ADD_TRANSACTIONS    2
#define CASE_UPD_CREDIT_LIMIT    3

int main() {
    int choice_action = 0;
    FILE *p_db_clients = NULL;
    FILE *p_transactions = NULL;
    FILE *p_db_clients_backup = NULL;
    Data data_client = {0};
    Data data_transaction = {0};
    printf("\n%s\n%s\n%s\n%s\n%s\n", "Actions", "1 Enter client data",
            "2 Enter transaction data", "3 Update base", "Enter action:");
    while (scanf("%d", &choice_action) != -1) {
        switch (choice_action) {
            case CASE_INPUT_DB_CLIENTS: {
                p_db_clients = fopen(FILENAME_DB_CLIENTS, "w+");
                if (p_db_clients == NULL) {
                    puts("No access\n");
                } else {
                    write_db_clients(p_db_clients, data_client);
                    fclose(p_db_clients);
                }
                break;
            }
            case CASE_ADD_TRANSACTIONS: {
                p_transactions = fopen(FILENAME_TRANSACTION, "w+");
                if (p_transactions == NULL) {
                    puts("No access\n");
                } else {
                    write_transactions(p_transactions, data_transaction);
                    fclose(p_transactions);
                }
                break;
            }
            case CASE_UPD_CREDIT_LIMIT: {
                p_db_clients = fopen(FILENAME_DB_CLIENTS, "r");
                p_transactions = fopen(FILENAME_TRANSACTION, "r");
                p_db_clients_backup = fopen(FILENAME_DB_CLIENTS_BACKUP, "w");
                if ((p_db_clients == NULL) || (p_transactions == NULL) || (p_db_clients_backup == NULL)) {
                    puts("No access\nexit\n");
                    if (p_db_clients != NULL) fclose(p_db_clients);
                    if (p_transactions != NULL) fclose(p_transactions);
                    if (p_db_clients_backup != NULL) fclose(p_db_clients_backup);
                } else {
                    upd_credit_limit_and_backup(p_db_clients, p_transactions, p_db_clients_backup,
                            data_client, data_transaction);
                    fclose(p_db_clients);
                    fclose(p_transactions);
                    fclose(p_db_clients_backup);
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
