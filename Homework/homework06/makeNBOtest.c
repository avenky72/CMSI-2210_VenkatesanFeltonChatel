#include <stdio.h>

extern unsigned int networkByteOrder(unsigned int number) {
    
    return htonl(number);
}

int main() {
    unsigned int testNumber = 5678;
    unsigned int conversionNumber = networkByteOrder(testNumber);
    printf("Input #: %u, Network Byte Order: %u\n", testNumber, conversionNumber);

    return 0;
}
