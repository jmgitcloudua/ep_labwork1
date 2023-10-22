CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SRCS = $(wildcard base*.c)
EXECS = $(SRCS:.c=)
OBJS = nn_base.o 

.PHONY: all clean

all: $(EXECS)

%: %.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $< $(OBJS) $(LDFLAGS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECS) $(OBJS) saved_weights.txt test_weights_saved.txt
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SRCS = $(wildcard base*.c)
EXECS = $(SRCS:.c=)
OBJS = nn_base.o