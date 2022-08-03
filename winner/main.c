#include <stdio.h>
#include <stdlib.h>

void win() {
    printf("%s", getenv("FLAG"));
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    char buf[100] = { 0 };
    printf("Congratulations! You have just won a contest! Input your name to claim your prize: \n");
    scanf("%s", buf);
}