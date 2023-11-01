#include <stdio.h>
#include <stdlib.h>
#define WHITESPACE " \t\n"

int countWords(FILE *file) {
  int wordCount = 0;
  char ch;
  ch = fgetc(file);
  while (ch != EOF) {
    if (strchr(WHITESPACE, ch)) {
      wordCount++;
    }
    ch = fgetc(file);
  }
  return wordCount;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s <file_name>\n", argv[0]);
    exit(1);
  }
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("can't open file: %s\n", argv[1]);
    exit(1);
  }
  int wordCount = countWords(file);
  fclose(file);
  printf("the file %s has %d words.\n", argv[1], wordCount);
  return 0;
}
