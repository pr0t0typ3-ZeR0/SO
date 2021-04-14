#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define ROWS 10
#define COLUMNS 10000

void ex1() {
  printf("PID:\t%d\nPPID:\t%d\n\n", getpid(), getppid());
}

void ex2() {
  pid_t child_pid = fork();
  ex1();
  if (child_pid)
    printf("Child PID from Parent:\t%d\n", child_pid);
  else
    _exit(0);
  wait(NULL);
}

void ex3() {
  for(int i = 0; i < 10; ++i) {
    if(!fork()) {
      ex1();
      _exit(i + 1);
    }
    int exit_status;
    wait(&exit_status);
    printf("%d\n", WEXITSTATUS(exit_status));
  }
}

void ex4() {
  for(int i = 0; i < 10; ++i)
    if(!fork())
      _exit(i + 1);

  int exit_status;
  while(wait(&exit_status) > 0)
    printf("Child %d\n", WEXITSTATUS(exit_status));
}

void ex5() {
  for(int i = 0; i < 10; ++i) {
    if(fork())
      _exit(0);
    ex1();
  }
}

void ex6(int const n, int const matrix[ROWS][COLUMNS]) {
  int found = 0;
  for(size_t i = 0; i < ROWS; ++i) {
    if(!fork()) {
      for(size_t j = 0; j < COLUMNS; ++j)
        if(matrix[i][j] == n) {
          printf("Row:\t %ld\n", i);
          found++;
      }
      _exit(found);
    }
  }

  int exit_status;
  for(size_t i = 0; i < ROWS; ++i) {
    wait(&exit_status);
      found += WEXITSTATUS(exit_status);
  }
  
  printf("%d ocurrences were found in the matrix\n", found);
}

void ex7(int const n, int const matrix[ROWS][COLUMNS]) {
  for(size_t i = 0; i < ROWS; ++i) {
    if(!fork()) {
      for(size_t j = 0; j < COLUMNS; ++j)
        if(matrix[i][j] == n) {
        _exit(i);
      }
      _exit(-1);
    }
  }

  int found[ROWS] = {0};
  int exit_status;
  for(size_t i = 0; i < ROWS; ++i) {
    wait(&exit_status);
    int l = WEXITSTATUS(exit_status);
    if (l != -1)
      found[l]++;
  }
  
  printf("Found %d in the rows: ", n);
  for(size_t i = 0; i < ROWS; ++i)
    if(found[i])
      printf(" %ld ", i);
  putchar('\n');
}

int main() {
  /* ex1(); */
  /* putchar('\n'); */

  // ex2();
  // putchar('\n');

  /* ex3(); */
  /* putchar('\n'); */

  /* ex4(); */
  /* putchar('\n'); */

  //ex5();
  //putchar('\n');

  int const matrix[ROWS][COLUMNS] = {0};
  
  ex6(1, matrix);

  return 0;
}
