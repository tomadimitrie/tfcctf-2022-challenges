#include <stdio.h>
#include <stdlib.h>

class Admin {
public:
    int a = 0;
    int b = 0;
    virtual void printFlag() {
        printf("%s\n", getenv("FLAG"));
    }
};

Admin admin;

class User {
public:
    int a = 0;
    int b = 0;
    virtual void inspect() {
        printf("success\n");
    }
};

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice;
    User *user = NULL;
    char *message = NULL;

    while (1) {
        printf(
            "1. Create user\n"
            "2. Inspect user\n"
            "3. Remove user\n"
            "4. Create message for the admins\n"
        );
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            user = new User;
            break;
        case 2:
            user->inspect();
            break;
        case 3:
            delete user;
            break;
        case 4:
            message = (char*) malloc(sizeof(User));
            getchar();
            fgets(message, sizeof(User), stdin);
            printf("%p %p\n", user, message);
            break;
        default:
            printf("invalid option\n");
        }
    }
}