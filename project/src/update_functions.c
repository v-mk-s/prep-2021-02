#include "utils.h"
#include "update_functions.h"
#include <stdio.h>

void update_credit_limit_and_backup(FILE *p_db_clients, FILE *p_transactions, FILE *p_db_clients_backup,
        Data *data_client, Data *data_transaction) {
    while ((fscanf(p_db_clients, "%d", &data_client->number) != EOF) &&
            (fscanf(p_db_clients, "%19s%19s", data_client->name, data_client->surname) != EOF) &&
            (fscanf(p_db_clients, "%29s%14s", data_client->address, data_client->phone_number) != EOF) &&
            (fscanf(p_db_clients, "%lf%lf%lf", &data_client->indebtedness,
                    &data_client->credit_limit, &data_client->cash_payments) != EOF)) {
        while (fscanf(p_transactions, "%d %lf", &data_transaction->number,
                &data_transaction->cash_payments) != EOF) {
            if ((data_client->number == data_transaction->number) &&
                    (data_transaction->cash_payments != 0)) {
                data_client->credit_limit += data_transaction->cash_payments;
            }
        }
        fprintf(p_db_clients_backup, "%-12d", data_client->number);
        fprintf(p_db_clients_backup, "%-11s%-11s", data_client->name, data_client->surname);
        fprintf(p_db_clients_backup, "%-16s%20s", data_client->address, data_client->phone_number);
        fprintf(p_db_clients_backup, "%12.2f%12.2f%12.2f\n", data_client->indebtedness,
                data_client->credit_limit, data_client->cash_payments);

        rewind(p_transactions);
    }
}
