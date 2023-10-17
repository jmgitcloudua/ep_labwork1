
# Make file for c programs

CFLAGS= -DNDEBUG

# source files

SRC = $(wildcard *.c)

# object files

OBJ = $(SRC:.c=.o)

# executable files

EXE = $(SRC:.c=)

# compiler

CC = gcc

# compiler flags

CFLAGS = -Wall -g

# linker flags

LDFLAGS = -lm

# default target

all: $(EXE)

# link

%: %.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# compile

%.o: %.c
	$(CC) $(CFLAGS) -c $<

# clean

clean:
	rm -f $(OBJ) $(EXE) *~

# end of file
