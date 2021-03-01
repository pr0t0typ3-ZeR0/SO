#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Wrong number of arguments");
    return 1;
  }

  int source = open(argv[1], O_RDONLY);
  if (source == -1) {
    printf("'%s': No such file or directory\n", argv[1]);
    return 1;
  }

  int dest = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644);

  char buf[BUF_SIZE];
  ssize_t size_read;
  while ((size_read = read(source, buf, BUF_SIZE)))
    write(dest, buf, size_read);

  close(source);
  close(dest);

  return 0;
}
