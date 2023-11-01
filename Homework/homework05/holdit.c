#include <stdio.h>
#include <time.h>

int main() {
    printf("This program will time how long you can hold your breath.\n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you absolutely have to exhale, press the enter key again.\n");
    printf("The duration will be displayed in minutes and seconds.\n");

    getchar();

    time_t start_time = time(NULL);

    getchar();

    time_t end_time = time(NULL);

    double duration = difftime(end_time, start_time);

    int minutes = (int)duration / 60;
    int seconds = (int)duration % 60;

    printf("You held your breath for: %d minute(s) and %d second(s).\n", minutes, seconds);

    return 0;
}
