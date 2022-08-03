#include <stdio.h>

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    printf("Welcome to the travel agency! Where do you want to go?\n");
    char buf[14];
    scanf("%15s", buf);
    printf("hmm... ");
    printf(buf);
    printf(" is an interesting destination!\n");
    printf("When do you want to go?\n");
    char buf2[200];
    scanf("%s", buf2);
    printf("okay, we have tickets for ");
    printf(buf2);
}