#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024

int my_system(const char *command) {
  size_t i = 0;
  char *args[SIZE];
  char *tk;
  char *str = malloc(strlen(command) + 1);
  strcpy(str, command);

  while((tk = strtok_r(str, " ", &str)))
    args[i++] = tk;
  args[i] = NULL;

  if(!fork())
    _exit(execvp(args[0], args));

  free(str);

  return 0;
}

int main(void) {
  char buf[SIZE];
  printf("Insert a command: ");
  fgets(buf, SIZE, stdin);
  buf[strcspn(buf, "\n")] = '\0';
  my_system(buf);

  return 0;
}
