CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = $(wildcard ex*.c)
EXECS = $(SRCS:.c=)
TEST_EXEC = unit_tests

.PHONY: all clean test

all: $(EXECS) $(TEST_EXEC)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

$(TEST_EXEC): unit_tests.c
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(EXECS) $(TEST_EXEC)

