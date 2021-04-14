#include <unistd.h>

int main(void) {
  execl("./ex3", "argv[0]", "argv[1]", "...", NULL);
  return 0;
}
