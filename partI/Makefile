CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = $(wildcard ex*.c)
EXECS = $(SRCS:.c=)

.PHONY: all clean

all: $(EXECS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECS)
