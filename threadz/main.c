#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

/*
   0x00000000000011d5 <+12>:	mov    esi,DWORD PTR fs:0xfffffffffffffffc
   0x00000000000011dd <+20>:	mov    r8d,DWORD PTR fs:0xfffffffffffffff8
   0x00000000000011e6 <+29>:	mov    edi,DWORD PTR fs:0xfffffffffffffff4
   0x00000000000011ee <+37>:	mov    ecx,DWORD PTR fs:0xfffffffffffffff0
   0x00000000000011f6 <+45>:	mov    edx,DWORD PTR fs:0xffffffffffffffec
   0x00000000000011fe <+53>:	mov    eax,DWORD PTR fs:0xffffffffffffffe8
*/

/*
Threads are so cool! And secure! So secure that I store all my secrets there
<br>
Note 1: The flag is broken into chunks of 4 characters, like this:
<br>
<code>volatile __thread unsigned int flag1 = '{CFT';</code>
<br>
The letters in the chunks are reversed for your convenience, and the chunks are defined in order
<br>
Note 2: The binary is intentionally not given. 
<br>
Note 3: The program will read 0x1000 bytes of shellcode, stored into a mmap-ed region with RWX permissions
*/

// gcc -o main main.c

#define PAGE_SIZE 0x1000

volatile __thread unsigned int flag1 = 'CCFT';
volatile __thread unsigned int flag2 = 'T{FT';
volatile __thread unsigned int flag3 = '43rh';
volatile __thread unsigned int flag4 = '4_Zd';
volatile __thread unsigned int flag5 = 'c_3r';
volatile __thread unsigned int flag6 = '}l00';

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    
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
    printf("gimme shellcodez!!!\n");
    read(STDIN_FILENO, shellcode, PAGE_SIZE);
    ((void (*)())shellcode)();
    munmap(shellcode, PAGE_SIZE);
}