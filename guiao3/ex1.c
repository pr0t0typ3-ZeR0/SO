#include <unistd.h>

int main(void) {
  execlp("ls", "ls", "-l", NULL);
  return 0;
}
