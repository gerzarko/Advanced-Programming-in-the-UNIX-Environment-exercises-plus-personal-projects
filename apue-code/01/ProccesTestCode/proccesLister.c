
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

pid_t getMyProccess() {
  DIR *dir;
  struct dirent *entry;

  dir = opendir("/proc");
  if (dir == NULL) {
    fprintf(stderr, "Unable to read proccesses: \n");
  }

  while ((entry = readdir(dir)) != NULL) {
    printf(("%s"), entry->d_name);
  }

  return (EXIT_SUCCESS);
}
