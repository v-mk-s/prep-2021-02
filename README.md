# Подготовительная программа по программированию на С/С++

## Домашнее задание №2

Дана программа в папке `project/src`.

Необходимо:
* Привести код программы в порядок
* Разобраться что программа делает
* Переписать программу используя несколько (хотя бы 2) модуля. Новая программа должна записывать в точности
	те же данные, что записывала исходная программа
* Для того, чтобы убедиться, что программа работает правильно, реализовать тест, который проверяет
успешность записи/перезаписи данных на диске (тоже в отдельном модуле).

Пример кода теста:

Основной модуль:
```c
void write_to_file(const char *filename, struct some *data);
void read_from_file(const char *filename, struct some *data);
```

Код теста
```c
#include "main_module.h"

void test_write_to_file() {
	const char *filename = "....";

	struct some expected_data;
	// Fill `expected_data` with some test values
	// and write them into the file `f`.
	// ...
	write_to_file(filename, &expected_data);

	struct some got_data;
	read_from_file(filename, &got_data);

	// Compare any field from `expected_data` with any field from `got_data`
	// ....
}
```

# Правила пользования тестирующим модулем
Tестирующий модуль лежит в папке project_test. Запускать его командой $make my_test,
$make my_build компилирует тестирующий модуль и исполняемый файл записывает в test.out
Функция write_to_file записывает данные в test_record.dat
