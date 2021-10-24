#ifndef PROJECT_INCLUDE_TEST_H_
#define PROJECT_INCLUDE_TEST_H_

#include <stdio.h>
#include "utils.h"

// основная тестирующая функция
void test();
// тестирования записи в файл filename
void test_write_to_file(const char *filename);
// записывает в filename данные из data
void write_to_file(const char *filename, Data *data);
// cчитывает из filename данные в data
void read_from_file(const char *filename, Data *data);
// сравнение 2х структур Data
int compare_Data(const Data *expected_data, const Data *got_data);

#endif  // PROJECT_INCLUDE_TEST_H_
