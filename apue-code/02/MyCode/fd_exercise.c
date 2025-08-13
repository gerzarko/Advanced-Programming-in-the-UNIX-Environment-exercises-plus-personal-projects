#define _POSIX_C_SOURCE 200809L // fix for compiler error of not importing stdio
#include <fcntl.h>              // new library for io opeations
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  int fileDesc;
  FILE *fileDesF;
  int fileDesFNumber;

  // printf("stdin:%d \n stdout:%d \n stderr:%d\n", STDIN_FILENO, STDOUT_FILENO,
  //        STDERR_FILENO);
  // //
  // printf("stdin %p", (void *)stdin);

  fileDesc = open("testfile.txt", O_RDONLY);
  if (fileDesc == -1) {
    fprintf(stderr, "file couldn't be open");
  }

  fprintf(stdout, "fd: %d\n", fileDesc);

  fileDesF = fopen("testfile.txt", "r");
  if (fileDesF == NULL) {
    fprintf(stderr, "file couldn't be open");
  }

  fileDesFNumber = fileno(fileDesF);
  fprintf(stdout, "fd read pointer: %d\n", fileDesFNumber);

  return EXIT_SUCCESS;
}
