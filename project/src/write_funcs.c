#include "utils.h"
#include "write_funcs.h"

#include <stdio.h>

void record_write(FILE *p_record, Data data_record) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            "1 Account number: ",
            "2 Name: ",
            "3 Surname: ",
            "4 Address: ",
            "5 Phone number: ",
            "6 Indebtedness: ",
            "7 Credit limit: ",
            "8 Cash payments: ");
    while(scanf("%d%19s%19s%29s%14s%lf%lf%lf", &data_record.number, data_record.name, data_record.surname,
            data_record.address, data_record.phone_number, &data_record.indebtedness, &data_record.credit_limit,
            &data_record.cash_payments) != -1) {
        fprintf(p_record, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", data_record.number, data_record.name,
                data_record.surname, data_record.address, data_record.phone_number, data_record.indebtedness,
                data_record.credit_limit, data_record.cash_payments);
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

void transaction_write(FILE *p_record, Data data_transaction) {
    printf("%s\n%s\n",
            "1 Account number: ",
            "2 Cash payments: ");
    while(scanf("%d %lf", &data_transaction.number, &data_transaction.cash_payments) != -1) {
        fprintf(p_record, "%-3d%-6.2f\n", data_transaction.number, data_transaction.cash_payments);
        printf("%s\n%s\n",
                "1 Account number:",
                "2 Cash payments: ");
    }
}
