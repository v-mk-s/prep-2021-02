# for project
TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
       project/src/main.c \
       project/src/utils.c \
       project/src/write_to_db_funcs.c \
       project/src/upd_funcs.c

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
       test_project/src/utils.c \
       test_project/src/test.c

.PHONY: my_all my_build my_rebuild my_test my_clean

my_all: my_clean my_test

$(TEST_TARGET): $(TEST_SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(TEST_HDRS_DIR) -o $(TEST_TARGET) $(CFLAGS) $(TEST_SRCS)

my_build: $(TEST_TARGET)

my_rebuild: my_clean my_build

my_test: $(TEST_TARGET)
	$(TEST_TARGET)

my_clean:
	rm -rf $(TEST_TARGET) *.dat

