#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(){
  char *buf = malloc(BUF_SIZE * sizeof(char));
  ssize_t size_read;

  while((size_read = read(STDIN_FILENO, buf, BUF_SIZE)))
    write(STDOUT_FILENO, buf, size_read);

  free(buf);

  return 0;
}
