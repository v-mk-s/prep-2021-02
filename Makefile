# for project
TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
       project/src/main.c \
       project/src/write_to_db_functions.c \
       project/src/update_functions.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check: $(TARGET)
	./linters/run.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat


# for test_project для тестирующего модуля
TEST_TARGET = ./test.out
TEST_HDRS_DIR = test_project/include

TEST_SRCS = \
       test_project/src/main.c \
       test_project/src/test.c

.PHONY: all_test build_test rebuild_test test_read_and_write clean_test

all_test: clean_test test_read_and_write

$(TEST_TARGET): $(TEST_SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(TEST_HDRS_DIR) -o $(TEST_TARGET) $(CFLAGS) $(TEST_SRCS)

build_test: $(TEST_TARGET)

rebuild_test: clean_test build_test

test_read_and_write: $(TEST_TARGET)
	$(TEST_TARGET)

clean_test:
	rm -rf $(TEST_TARGET) *.dat

