#include "utils.h"
#include "upd_funcs.h"
#include <stdio.h>

void upd_credit_limit_and_backup(FILE *p_db_clients, FILE *p_transactions, FILE *p_db_clients_backup,
        Data data_client, Data data_transaction) {
    while ((fscanf(p_db_clients, "%d%19s%19s%29s%14s", &data_client.number,  data_client.name,
            data_client.surname, data_client.address, data_client.phone_number) != -1) &&
			(fscanf(p_db_clients, "%lf%lf%lf", &data_client.indebtedness,
            &data_client.credit_limit, &data_client.cash_payments) != -1)) {
        while (fscanf(p_transactions, "%d %lf", &data_transaction.number,
                &data_transaction.cash_payments) != -1) {
            if ((data_client.number == data_transaction.number) && (data_transaction.cash_payments != 0)) {
                data_client.credit_limit += data_transaction.cash_payments;
            }
        }
        fprintf(p_db_clients_backup, "%-12d%-11s%-11s%-16s%20s", data_client.number,
                data_client.name, data_client.surname, data_client.address, data_client.phone_number);
        fprintf(p_db_clients_backup, "%12.2f%12.2f%12.2f\n", data_client.indebtedness,
                data_client.credit_limit, data_client.cash_payments);
        rewind(p_transactions);
    }
}
