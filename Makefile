CC=gcc
CFLAGS=-Wall -Werror -Wextra
BUILDDIR=build/
SRCDIR=src/

all: main

main: main.o print.o objects.o init.o movements.o
	$(CC) $(CFLAGS) $(BUILDDIR)main.o $(BUILDDIR)print.o \
	$(BUILDDIR)objects.o $(BUILDDIR)init.o $(BUILDDIR)movements.o \
	-lncurses -o $(BUILDDIR)main
main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(BUILDDIR)main.o

print.o: $(SRCDIR)print.c
	$(CC) $(CFLAGS) -c $(SRCDIR)print.c -lncurses -o $(BUILDDIR)print.o

objects.o: $(SRCDIR)objects.c
	$(CC) $(CFLAGS) -c $(SRCDIR)objects.c -o $(BUILDDIR)objects.o

init.o: $(SRCDIR)init.c
	$(CC) $(CFLAGS) -c $(SRCDIR)init.c -lncurses -o $(BUILDDIR)init.o

movements.o: $(SRCDIR)movements.c
	$(CC) $(CFLAGS) -c $(SRCDIR)movements.c -lncurses -o $(BUILDDIR)movements.o

clean:
	rm -rf $(BUILDDIR)*.o

rebuild: clean all
