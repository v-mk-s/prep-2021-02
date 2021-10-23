#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#define FILENAME_DB_CLIENTS "record.dat"
#define FILENAME_TRANSACTION "transaction.dat"
#define FILENAME_DB_CLIENTS_BACKUP "blackrecord.dat"

typedef struct {
    int number;
    char name[20];
    char surname[20];
    char address[30];
    char phone_number[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} Data;

#endif  // PROJECT_INCLUDE_UTILS_H_

