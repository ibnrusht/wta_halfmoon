CC=gcc
CFLAGS=-Wall -Werror -Wextra
BUILDDIR=build/
SRCDIR=src/

all: main

main: main.o print.o objects.o init.o
	$(CC) $(CFLAGS) $(BUILDDIR)main.o $(BUILDDIR)print.o $(BUILDDIR)objects.o $(BUILDDIR)init.o -lncurses -o $(BUILDDIR)main
main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(BUILDDIR)main.o

print.o: $(SRCDIR)print.c
	$(CC) $(CFLAGS) -c $(SRCDIR)print.c -lncurses -o $(BUILDDIR)print.o

objects.o: src/objects.c
	$(CC) $(CFLAGS) -c $(SRCDIR)objects.c -o $(BUILDDIR)objects.o

init.o: src/init.c
	$(CC) $(CFLAGS) -c $(SRCDIR)init.c -lncurses -o $(BUILDDIR)init.o

clean:
	rm -rf $(BUILDDIR)*.o
	rm -rf $(BUILDDIR)*.out

rebuild: clean all
