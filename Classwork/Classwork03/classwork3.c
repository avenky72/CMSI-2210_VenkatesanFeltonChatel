#include <stdlib.h>
#include <stdio.h>


int main(int args, char * argv[] ) {
   
    char input[50];
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf",
        "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November",
        "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
        "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"
    };

    for (int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]);
        if (isalpha(c)) {
            int index = c - 'A'; 
            printf("%s ", nato[index]); 
        } else if (c == ' ') { 
            printf(" "); 
        }
    }

    printf("\n");

    return 0;
}
