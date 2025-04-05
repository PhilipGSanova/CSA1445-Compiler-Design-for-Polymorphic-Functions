#include <stdio.h>

int main() {
    char com[30];
    printf("Enter comment: ");
    fgets(com, 30, stdin);

    if (com[0] == '/' && (com[1] == '/' || (com[1] == '*' && strchr(com, '/') > com + 2)))
        printf("It is a comment\n");
    else
        printf("It is not a comment\n");

    return 0;
}
