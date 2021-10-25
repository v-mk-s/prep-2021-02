#ifndef PROJECT_INCLUDE_UPDATE_FUNCTIONS_H_
#define PROJECT_INCLUDE_UPDATE_FUNCTIONS_H_

#include "utils.h"
#include <stdio.h>

/* обновление БД клиентов (FILENAME_DB_CLIENTS) используя
 * БД транзакций (FILENAME_TRANSACTION) и бэкап БД клиентов (FILENAME_DB_CLIENTS) в
 * БД (FILENAME_DB_CLIENTS_BACKUP)
 * обновление кредитного лимита клиентов (изменение репутации клиентов в глазах банка)
 * */
void update_credit_limit_and_backup(FILE *p_db_clients, FILE *p_transactions, FILE *p_db_clients_backup,
        Data *data_client, Data *data_transaction);

#endif  // PROJECT_INCLUDE_UPDATE_FUNCTIONS_H_
