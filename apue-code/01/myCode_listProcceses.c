
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFSIZE
#define BUFFSIZE 32768
#endif

int main(int argc, char *argv[]) {

  DIR *allProccess = opendir("/proc/");
  if (allProccess == NULL) {
    fprintf(stderr, "Unable to read proccesses: \n");
  }

  struct dirent *entry;
  while ((entry = readdir(allProccess)) != NULL) {
    printf("%s\n", entry->d_name);
  }
  closedir(allProccess);

  return (EXIT_SUCCESS);
}
