#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* toNATO(char c) {
    static char* nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf",
        "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November",
        "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
        "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"
    };

    if (isalpha(c)) {
        return nato[toupper(c) - 'A'];
    } else {
        return "";
    }
}

int main() {
    char input[50];
    
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            printf("\n");
        } else {
            char* nato_word = toNATO(input[i]);
            if (strlen(nato_word) > 0) {
                printf("%s ", nato_word);
            }
        }
    }

    return 0;
}
