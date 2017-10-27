CC=gcc
CFLAGS=-g -std=c99 -D_GNU_SOURCE -Wall
PROG=hanoi
SRC=main.c hanoi.c pile.c
OBJ=${SRC:.c=.o}

.PHONY: all clean doc

all:	main doc

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -rf *.o html $(PROG)

doc:
			doxygen