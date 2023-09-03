 #include <stdio.h>
#include <stdlib.h>

   int main( int argc, char * argv[] ) {

    char name;
    printf("What is your name: \n");
    gets(name);
    printf("Hello %s", name);
    return(0);

   }
