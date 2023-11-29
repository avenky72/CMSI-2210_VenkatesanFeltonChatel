#include <stdio.h>

int main() {
    unsigned int valueCheck = 1;
    char *pointerCheckValue = (char *)&valueCheck;

    if (*pointerCheckValue == 1) {
        printf("Your computer is little-endian.\n");
    } else {
        printf("Your computer is big-endian.\n");
    }
    return 0;
}
