#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

  (void)argc; // to avoid the flag to bother me

  char *fileSource;
  char *fileDestination;
  int c; // character in asci from the stream being read

  fileSource = argv[1];
  fileDestination = argv[2];

  FILE *FileOpenSrc = fopen(fileSource, "r");
  if (FileOpenSrc == NULL) {
    fprintf(stderr, "couldnt open the file");
    exit(EXIT_FAILURE);
  };

  FILE *FileOpenDes = fopen(fileDestination, "w");
  if (FileOpenDes == NULL) {
    fprintf(stderr, "couldnt open the file");
    exit(EXIT_FAILURE);
  };

  while ((c = fgetc(FileOpenSrc)) != EOF) {
    if (putc(c, FileOpenDes) == EOF) {
      fprintf(stderr, "Unable to write: %c\n", c);
      exit(EXIT_FAILURE);
    };
  }

  fclose(FileOpenSrc);
  fclose(FileOpenDes);

  return EXIT_SUCCESS;
}
