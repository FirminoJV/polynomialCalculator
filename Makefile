CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

all: calculator

calculator: interface.c polynomial.c polynomial.h
	$(CC) $(CFLAGS) interface.c polynomial.c -o calculator $(LDFLAGS)

clean:
	rm -f calculator *.o 