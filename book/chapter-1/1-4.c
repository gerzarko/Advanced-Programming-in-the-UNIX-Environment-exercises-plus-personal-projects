#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main(int argc, char **argv) {

  int n;
  char buf[BUFFSIZE];

  (void)argc;
  (void)argv;

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      printf("write error");
      exit(EXIT_FAILURE);
    }
    if (n < 0) {
      printf("read error");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}

// #include <errno.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
//
// /* We'll see later why / how we picked this number. */
// #ifndef BUFFSIZE
// #define BUFFSIZE 32768
// #endif
//
// int
// main(int argc, char **argv) {
// 	int n;
// 	char buf[BUFFSIZE];
//
// 	/* cast to void to silence compiler warnings */
// 	(void)argc;
// 	(void)argv;
//
// 	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
// 		if (write(STDOUT_FILENO, buf, n) != n) {
// 			fprintf(stderr, "Unable to write: %s\n",
// strerror(errno)); 			exit(EXIT_FAILURE);
// 		}
// 	}
//
// 	if (n < 0) {
// 		fprintf(stderr, "Unable to read: %s\n", strerror(errno));
// 		exit(EXIT_FAILURE);
// 	}
//
// 	return(EXIT_SUCCESS);
// }
