#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage: %s <N>\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);
  printf("Multiplication Table from 2 to %d\n", n);
  printf("-------------------------------\n");
  for (int i = 2; i <= n; i++) {
    //messing around with format specifiers
    printf("%2d |  ", i);
    for (int j = 2; j <= n; j++) {
      printf("%4d ", i * j);
    }
    printf("\n");
  }
  return 0;
}
