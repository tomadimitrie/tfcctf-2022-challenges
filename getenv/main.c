#include <stdio.h>

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    printf("surprise me\n");

    char s[20] = { 0 };
    fgets(s, sizeof s, stdin);
    printf(s);
}