#include "utils.h"
#include "upd_funcs.h"

#include <stdio.h>

void upd_base(FILE *p_record, FILE  *p_transaction, FILE *p_blackrecord,
		Data data_record, Data data_transaction) {
	while(fscanf(p_record, "%d%19s%19s%29s%14s%lf%lf%lf",  &data_record.number,  data_record.name,
			data_record.surname, data_record.address, data_record.phone_number, &data_record.indebtedness,
			&data_record.credit_limit, &data_record.cash_payments) != -1) {
		while (fscanf(p_transaction, "%d %lf", &data_transaction.number, &data_transaction.cash_payments) != -1) {
			if ((data_record.number == data_transaction.number) && (data_transaction.cash_payments != 0)) {
				data_record.credit_limit += data_transaction.cash_payments;
			}
		}
		fprintf(p_blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", data_record.number, data_record.name,
				data_record.surname, data_record.address, data_record.phone_number, data_record.indebtedness,
				data_record.credit_limit, data_record.cash_payments);
		rewind(p_transaction);
	}
}
