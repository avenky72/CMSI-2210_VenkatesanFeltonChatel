#include <stdio.h>
#include <stdlib.h>

#define MAX_COPIES 10

int main(int argc, char *argv[]) {
  // Read the command line arguments.
  char *filename;
  int copies = 1;
  if (argc >= 2) {
    filename = argv[1];
    if (argc >= 3) {
      copies = atoi(argv[2]);
      if (copies < 1 || copies > MAX_COPIES) {
        printf("Usage: %s <filename> <copies> (copies must be between 1 and %d)\n", argv[0], MAX_COPIES);
        return 1;
      }
    }
  } else {
    // Prompt the user for the file name and number of copies.
    printf("Enter the name of the file to duplicate: ");
    scanf("%s", filename);
    printf("Enter the number of copies to make: ");
    scanf("%d", &copies);
    while (copies < 1 || copies > MAX_COPIES) {
      printf("The number of copies must be between 1 and %d. Try again: ", MAX_COPIES);
      scanf("%d", &copies);
    }
  }

  // Open the input file.
  FILE *input = fopen(filename, "r");
  if (!input) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  // Read the first line of the input file.
  char line[1024];
  fgets(line, sizeof(line), input);

  // Convert the number on the first line to an int.
  int count = atoi(line);

  // Display a message to the user.
  printf("File %s is open. Will copy %d lines.\n", filename, count);

  // Create an output file name.
  char output_filename[1024];
  sprintf(output_filename, "output.txt");

  // Open the output file.
  FILE *output = fopen(output_filename, "w");
  if (!output) {
    printf("Error opening file %s\n", output_filename);
    return 1;
  }

  // Write the contents of the input file to the output file, multiple times.
  for (int i = 0; i < copies; i++) {
    for (int j = 0; j < count; j++) {
      fgets(line, sizeof(line), input);
      fputs(line, output);
    }
    fputc('\n', output);

    // Seek back to the start of the input file, just after the first line.
    fseek(input, 0, SEEK_SET);
    fgetc(input);
  }

  // Close both files.
  fclose(input);
  fclose(output);

  // Check the output file to make sure that it contains the expected number of lines.
  input = fopen(output_filename, "r");
  int output_count = 0;
  while (fgets(line, sizeof(line), input) != NULL) {
    output_count++;
  }
  fclose(input);

  if (output_count != copies * count) {
    printf("Error: output file does not contain the expected number of lines.\n");
    return 1;
  }

  return 0;
}
