#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define PAGE_SIZE 0x1000

void alarmHandler() {
    printf("Too slow!\n");
    exit(0);
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    void *flag = mmap(
        NULL,
        PAGE_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        0,
        0
    );
    memcpy(flag, "TFCCTF{B3st_3gg_hunt3r}", 24);

    void *shellcode = mmap(
        NULL,
        PAGE_SIZE,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_PRIVATE | MAP_ANONYMOUS,
        0,
        0
    );
    if (shellcode == MAP_FAILED) {
        printf("error code 0x1, contact admin\n");
    }
    signal(SIGALRM, alarmHandler);
    alarm(2);
    printf("let's start\n");
    read(STDIN_FILENO, shellcode, PAGE_SIZE);
    ((void (*)())shellcode)();
    printf("done executing\n");
    munmap(shellcode, PAGE_SIZE);
}