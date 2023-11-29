#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

extern unsigned int networkByteOrder(unsigned int number) {

    return htonl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <value>\n", argv[0]);

        return 1;
    }

    unsigned int input = strtoul(argv[1], NULL, 0);
    unsigned int conversion = networkByteOrder(input);
    printf("Input #: %u, Network Byte Order: %u\n", input, conversion);

    return 0;
}
