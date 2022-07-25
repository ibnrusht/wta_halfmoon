CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: main.o

main.o: main.c
	$(CC) $(CFLAGS) main.c
