#include "test.h"
#include "main.h"
#include "utils.h"

/*
void test() {
    test_write_to_file(filename_record);
    // test_write_to_file(filename_transaction);
    // test_write_to_file(filename_blackrecord);
}
*/

/*
void test_write_to_file(const char *filename) {
	List_Data expected_data;
    Data data_test;

    // Fill `expected_data` with some test values
	// and write them into the file `f`.

    //1я запись БД record
    data_test = {.number = 1; name = "name1"; surname = "surname1"; address = "address1"; phone_number = "phone1";
            indebtedness = 80; credit_limit = 200; cash_payments = 50};
    expected_data.Data[0] = data_test;
    //2я запись БД record
    data_test = {.number = 2; name = "name2"; surname = "surname2"; address = "address2"; phone_number = "phone2";
            indebtedness = 800; credit_limit = 2000; cash_payments = 500};
    expected_data.Data[1] = data_test;
    //3я запись БД record
    data_test = {.number = 3; name = "name3"; surname = "surname3"; address = "address3"; phone_number = "phone3";
            indebtedness = 8000; credit_limit = 20000; cash_payments = 5000};
    expected_data.Data[2] = data_test;

	write_to_file(filename, &expected_data);

	List_Data got_data;
	read_from_file(filename, &got_data);

	// Compare any field from `expected_data` with any field from `got_data`
	
    expected_data.Data[0] = got_data.Data[0];
    expected_data.Data[1] = got_data.Data[1];
    expected_data.Data[2] = got_data.Data[2];
    
}
*/

// void write_to_file(const char *filename, List_Data *data) {};

// void read_from_file(const char *filename, List_Data *data) {};
