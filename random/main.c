#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
I created a random number generator as a project. Unfortunately it has only one option, but I will add more soon!
*/

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    srand(time(NULL));

    printf(
        "Menu: \n"
        "1. Generate number\n"
    );
    int option;
    scanf("%d", &option);
    switch (option) {
        case 1:
            printf("%d", rand());
            break;
        case 1337:
            printf("%s", getenv("FLAG"));
            break;
        default:
            printf("wrong option");
    }
}