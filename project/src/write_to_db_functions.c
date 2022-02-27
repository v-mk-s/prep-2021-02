#include "utils.h"
#include "write_to_db_functions.h"
#include <stdio.h>

void write_db_clients(FILE *p_db_clients, Data *data_client) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            "1 Account number: ",
            "2 Name: ",
            "3 Surname: ",
            "4 Address: ",
            "5 Phone number: ",
            "6 Indebtedness: ",
            "7 Credit limit: ",
            "8 Cash payments: ");
    while ((scanf("%d", &data_client->number) != EOF) &&
            (scanf("%19s%19s", data_client->name, data_client->surname) != EOF) &&
            (scanf("%29s%14s", data_client->address, data_client->phone_number) != EOF) &&
            (scanf("%lf%lf%lf", &data_client->indebtedness,
                    &data_client->credit_limit, &data_client->cash_payments) != EOF)) {
        fprintf(p_db_clients, "%-12d", data_client->number);
        fprintf(p_db_clients, "%-11s%-11s", data_client->name, data_client->surname);
        fprintf(p_db_clients, "%-16s%20s", data_client->address, data_client->phone_number);
        fprintf(p_db_clients, "%12.2f%12.2f%12.2f\n", data_client->indebtedness,
                data_client->credit_limit, data_client->cash_payments);

        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
                "1 Account number: ",
                "2 Name: ",
                "3 Surname: ",
                "4 Address: ",
                "5 Phone number: ",
                "6 Indebtedness: ",
                "7 Credit limit: ",
                "8 Cash payments: ");
    }
}

void write_transactions(FILE *p_transactions, Data *data_transaction) {
    printf("%s\n%s\n",
            "1 Account number: ",
            "2 Cash payments: ");

    while (scanf("%d %lf", &data_transaction->number, &data_transaction->cash_payments) != EOF) {
        fprintf(p_transactions, "%-3d%-6.2f\n", data_transaction->number, data_transaction->cash_payments);
        printf("%s\n%s\n",
                "1 Account number:",
                "2 Cash payments: ");
    }
}