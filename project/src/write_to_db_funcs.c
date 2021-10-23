#include "utils.h"
#include "write_to_db_funcs.h"
#include <stdio.h>

void write_db_clients(FILE *p_db_clients, Data data_client) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            "1 Account number: ",
            "2 Name: ",
            "3 Surname: ",
            "4 Address: ",
            "5 Phone number: ",
            "6 Indebtedness: ",
            "7 Credit limit: ",
            "8 Cash payments: ");
    while ((scanf("%d%19s%19s%29s%14s", &data_client.number,  data_client.name,
            data_client.surname, data_client.address, data_client.phone_number) != -1) &&
            (scanf("%lf%lf%lf", &data_client.indebtedness,
            &data_client.credit_limit, &data_client.cash_payments) != -1)) {
        fprintf(p_db_clients, "%-12d%-11s%-11s%-16s%20s", data_client.number,
                data_client.name, data_client.surname, data_client.address, data_client.phone_number);
        fprintf(p_db_clients, "%12.2f%12.2f%12.2f\n", data_client.indebtedness,
                data_client.credit_limit, data_client.cash_payments);
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

void write_transactions(FILE *p_transactions, Data data_transaction) {
    printf("%s\n%s\n",
            "1 Account number: ",
            "2 Cash payments: ");
    while (scanf("%d %lf", &data_transaction.number, &data_transaction.cash_payments) != -1) {
        fprintf(p_transactions, "%-3d%-6.2f\n", data_transaction.number, data_transaction.cash_payments);
        printf("%s\n%s\n",
                "1 Account number:",
                "2 Cash payments: ");
    }
}
