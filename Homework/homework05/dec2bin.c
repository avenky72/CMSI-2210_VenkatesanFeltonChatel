#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned int number;
  if (argc >= 2) {
    number = atoi(argv[1]);
  } else {
    printf("Enter a base-10 number: ");
    scanf("%u", &number);
  }
  char binary[33];
  binary[32] = '\0';
  for (int i = 0; i < 32; i++) {
  binary[31 - i] = (number & (1u << i)) ? '1' : '0';
}
  printf("%s\n", binary);
  return 0;
}
