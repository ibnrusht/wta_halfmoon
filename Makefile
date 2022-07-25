CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: main.o

main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o build/main.o
