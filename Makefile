CC = gcc
CFLAGS = -Wall -std=c11

all: ann

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

ann.o: ann.c matrix.h
	$(CC) $(CFLAGS) -c ann.c

ann: ann.o matrix.o
	$(CC) $(CFLAGS) ann.o matrix.o -o ann

clean:
	rm -f *.o ann ann.exe
