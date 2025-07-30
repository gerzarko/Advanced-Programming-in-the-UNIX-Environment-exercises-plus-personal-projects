
#include <stdio.h>

#ifndef BUFFSIZE
#define BUFFSIZE 32768
#endif

int main(int argc, char *argv[]) {

  int c;
  FILE *fileToRead;

  fileToRead = fopen(argv[1], "r");
  while ((c = fgetc(fileToRead)) != EOF) {
    if (putc(c, stdout) == EOF) {
      fprintf(stderr, "unable to write %c", c);
    }
  }
}
