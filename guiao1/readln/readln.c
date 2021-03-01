#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

ssize_t readln(int fd, char *line, size_t size) {
  ssize_t i = 0;
  for (ssize_t bytes_read; i < size; i++) {
    bytes_read = read(fd, &line[i], 1);
    if (line[i] == '\n' || bytes_read == 0)
      break;
  }
  line[i++] = '\n';
  return i;
}

ssize_t readln2(int fd, char *line, size_t size) {
  ssize_t bytes_read = read(fd, line, size);

  size_t line_len;
  for (line_len = 0; line[line_len] != '\n' && line_len < bytes_read; line_len++);
  line[line_len++] = '\n';

  lseek(fd, line_len - bytes_read, SEEK_CUR);
  return line_len;
}
