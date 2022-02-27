#ifndef PROJECT_INCLUDE_WRITE_TO_DB_FUNCTIONS_H_
#define PROJECT_INCLUDE_WRITE_TO_DB_FUNCTIONS_H_

#include "utils.h"
#include <stdio.h>

// запись (дозапись) в БД записей (FILENAME_DB_CLIENTS)
void write_db_clients(FILE *p_db_clients, Data *data_client);

// запись (дозапись) в БД транзакций (cash_payments) (FILENAME_TRANSACTION)
void write_transactions(FILE *p_transactions, Data *data_transaction);

#endif  // PROJECT_INCLUDE_WRITE_TO_DB_FUNCTIONS_H_
