#include <stdio.h>
#include <string.h>

unsigned long long phi(unsigned long long n) {
    unsigned long long result = n;
    unsigned long long i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


int main() {
    char s[100000] = { 0 };
    unsigned long long *n;
    fgets(s, sizeof s, stdin);
    strtok(s, "\n");
    n = (unsigned long long *)s;
    if (phi(*n) == 509728320) {
        printf("correct!\n");
    } else {
        printf("sorry\n");
    }
    return 0;
}