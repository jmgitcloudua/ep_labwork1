CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SRCS = $(wildcard base*.c)
EXECS = $(SRCS:.c=)
OBJS = nn_base.o 
TEST_EXEC = unit_tests

.PHONY: all clean

all: $(EXECS) $(TEST_EXEC)

%: %.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $< $(OBJS) $(LDFLAGS)

$(TEST_EXEC): unit_tests.c
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECS) $(OBJS) $(TEST_EXEC) saved_weights.txt test_weights_saved.txt
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SRCS = $(wildcard base*.c)
EXECS = $(SRCS:.c=)
OBJS = nn_base.o