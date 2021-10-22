#ifndef PROJECT_INCLUDE_UPD_FUNCS_H_
#define PROJECT_INCLUDE_UPD_FUNCS_H_

#include "utils.h"

#include <stdio.h>

// обновление БД (filename_blackrecord) используя
// БД записей (filename_record) и БД транзакций (filename_transaction)
void upd_base(FILE *p_record, FILE *p_transaction, FILE *p_blackrecord,
        Data data_record, Data data_transaction);

#endif  // PROJECT_INCLUDE_UPD_FUNCS_H_
