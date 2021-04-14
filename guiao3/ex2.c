#include <unistd.h>
#include <sys/types.h>

int main(void) {
  pid_t pid;
  if(!(pid = fork())) {
    execlp("ls", "ls", "-l", NULL);
  }
  return 0;
}
