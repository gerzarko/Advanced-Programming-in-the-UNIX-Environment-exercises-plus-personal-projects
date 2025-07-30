
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFSIZE
#define BUFFSIZE 32768
#endif

int main(int argc, char *argv[]) {

  int c;
  FILE *fileToRead;

  fileToRead = fopen(argv[1], "r");
  if (fileToRead == NULL) {
    fprintf(stderr, "couldn't read file %s", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((c = fgetc(fileToRead)) != EOF) {
    if (putc(c, stdout) == EOF) {
      fprintf(stderr, "unable to write %c", c);
      exit(EXIT_FAILURE);
    }
  }

  fclose(fileToRead);

  return EXIT_SUCCESS;
}
