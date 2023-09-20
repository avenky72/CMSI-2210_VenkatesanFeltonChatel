#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char * argv[] ) {
   #define MAX_ENTRY = 25;

   char input[25];
   for (int i =0; i < MAX_ENTRY; i++ ) {
      printf( "\n  enter an integer: " );
      fgets(input, 10, stdin);
      if (input == -9999):
        break;
      else:
        printf("input is : %s\n, input);
        value = atoi(input);
        printf( "\n     got: %d", input[i] );

   }

}
