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
  char binary[32];
  for (int i = 31; i >= 0; i--) {
    binary[i] = (number & (1 << i)) ? '1' : '0';
  }
  return binary;
}
