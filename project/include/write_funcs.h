#ifndef PROJECT_INCLUDE_WRITE_FUNCS_H_
#define PROJECT_INCLUDE_WRITE_FUNCS_H_

#include "utils.h"

#include <stdio.h>

// запись (дозапись) в БД записей (filename_record)
void record_write(FILE *p_record, Data data_record);

// запись (дозапись) в БД транзакций (filename_transaction)
void transaction_write(FILE *p_record, Data data_transaction);

#endif  // PROJECT_INCLUDE_WRITE_FUNCS_H_
