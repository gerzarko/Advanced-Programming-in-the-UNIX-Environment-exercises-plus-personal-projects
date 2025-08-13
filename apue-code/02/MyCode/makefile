
CC = cc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic -I.

fd: main.o
	$(CC) $(CFLAGS) -o fd fd_exercise.o

main.o: fd_exercise.c
	$(CC) $(CFLAGS) -c fd_exercise.c

clean:
	rm -f *.o fd
