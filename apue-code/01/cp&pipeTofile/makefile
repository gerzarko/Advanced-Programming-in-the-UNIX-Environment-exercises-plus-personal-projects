
CC = cc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic -I.

pipe: main.o
	$(CC) $(CFLAGS) -o pipe main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o pipe
