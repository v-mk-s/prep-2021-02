#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#define filename_record "record.dat"
#define filename_transaction "transaction.dat"
#define filename_blackrecord "blackrecord.dat"

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

