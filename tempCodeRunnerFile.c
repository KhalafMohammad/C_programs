#include <stdio.h>

int main(int argc, char **argv) {
  const int i=10;
  printf("const i: %d is not const: %d", i, (*(int *)&i)=15);
  return 0;
}