#include <stdio.h>
#include <string.h>
#include "test.h"
#include "utils.h"

void test_write_to_file(const char *filename) {
    if (!strncmp(filename, FILENAME_DB_CLIENTS, 80)) {
        Data expected_data = {1, "name1", "surname1", "address1", "phone1", 80, 200, 50};
        // 1 1 name1 surname1 address1 phone1 80 200 50

        write_to_file(filename, &expected_data);

        Data got_data = {0};
	    read_from_file(filename, &got_data);

        if (compare_Data(&expected_data, &got_data) != -1) {
            puts("***** TEST SUCCEED *****\n");
        } else {
            puts("Files mismatches\n");
        }

    } else {
        puts("Error in filename\n");
    };
}

void write_to_file(const char *filename, Data *data) {
    FILE *p_db_clients = NULL;
    p_db_clients = fopen(filename, "w+");

    if (p_db_clients == NULL) {
        puts("No access to file\n");
    } else {
        fprintf(p_db_clients, "%-12d%-11s%-11s%-16s%20s", data->number,
                data->name, data->surname, data->address, data->phone_number);
        fprintf(p_db_clients, "%12.2f%12.2f%12.2f\n", data->indebtedness,
                data->credit_limit, data->cash_payments);
    
        fclose(p_db_clients);
    };
}

void read_from_file(const char *filename, Data *data) {
    FILE *p_db_clients = NULL;
    p_db_clients = fopen(filename, "r");
    
    if (p_db_clients == NULL) {
        puts("No access to file\n");
    } else {
        fscanf(p_db_clients, "%d%19s%19s%29s%14s", &data->number,  data->name,
                data->surname, data->address, data->phone_number);
        fscanf(p_db_clients, "%lf%lf%lf", &data->indebtedness,
                &data->credit_limit, &data->cash_payments);
    
        fclose(p_db_clients);
    };
}

int compare_Data(const Data *expected_data, const Data *got_data) {
    if ((expected_data->number == got_data->number) &&
        !strncmp(expected_data->name, got_data->name, 80) &&
        !strncmp(expected_data->surname, got_data->surname, 80) &&
        !strncmp(expected_data->address, got_data->address, 80) &&
        !strncmp(expected_data->phone_number, got_data->phone_number, 80) &&
        (expected_data->indebtedness == got_data->indebtedness) &&
        (expected_data->credit_limit == got_data->credit_limit) &&
        (expected_data->cash_payments == got_data->cash_payments)) {
            return 0;
        }
    return -1;
}
