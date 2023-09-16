#include <stdlib.h>
#include <stdio.h>


int main(int args, char * argv[] ) {
    
  char input[50];
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    for (int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]); 
        if (isalpha(c)) { 
            for (int j = 0; j < 26; j++) {
                if (c == alphabet[j]) {
                    printf("%s ", morse[j]); 
                    break;
                }
            }
        } else if (c == ' ') {
            printf(" "); 
        }
    }

    printf("\n");

    return 0;
}
