#include "readln.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  char line[BUF_SIZE];
  int line_len = readln(fd, line, BUF_SIZE);

  write(STDOUT_FILENO, line, line_len);

  close(fd);
  return 0;
}
