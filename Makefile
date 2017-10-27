CC=gcc
CFLAGS=-g -std=c99 -D_GNU_SOURCE -Wall
PROG=hanoi
SRC=main.c hanoi.c stack.c
OBJ=${SRC:.c=.o}
HDR=${SRC:.c=.h}

.PHONY: all clean doc

all:	main doc

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c $(HDR)
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -rf *.o html $(PROG)

doc:
			doxygen
