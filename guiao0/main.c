#include "vector.h"
#include <stdio.h>

#define SIZE 10

int main() {

  int v[SIZE];
  int fillValue = 5;

  printf("Filling a vector with %d:\n{", fillValue);
  fill(v, SIZE, fillValue);
  for (int i = 0; i < SIZE - 1; i++)
    printf("%d, ", v[i]);
  printf("%d}\n\n", v[SIZE - 1]);

  int vs[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int findValue = 7;

  printf("Finding %d in the vector {", findValue);
  for (int i = 0; i < SIZE - 1; i++)
    printf("%d, ", vs[i]);
  printf("%d}:\n", vs[SIZE - 1]);
  int found = find(vs, SIZE, findValue);
  (found == -1)
      ? printf("Value %d not found\n\n", findValue)
      : printf("Value %d found in index %d of vector\n\n", findValue, found);

  int start = 2;
  int end = 5;

  printf("Finding %d between indexes %d and %d of the vector {", findValue, start, end);
  for (int i = 0; i < SIZE - 1; i++)
    printf("%d, ", vs[i]);
  printf("%d}:\n", vs[SIZE - 1]);
  found = find(vs + start, end - start + 1, findValue);
  (found == -1)
      ? printf("Value %d not found\n", findValue)
      : printf("Value %d found in index %d of vector\n", findValue, start + found);
  return 0;
}
