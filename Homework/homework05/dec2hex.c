#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned long number;
    int bits = 32;

    if (argc < 2) {
        printf("Enter a base-10 number: ");
        scanf("%lu", &number);
    } else {
        number = strtoul(argv[1], NULL, 10);
        if (argc > 2) {
            bits = atoi(argv[2]);
        }
    }

    if (bits == 32) {
        printf("0x%08X\n", (unsigned int)number);
    } else if (bits == 64) {
        printf("0x%016lX\n", number);
    } else {
        printf("Invalid bit size.\n");
    }

    return 0;
}
