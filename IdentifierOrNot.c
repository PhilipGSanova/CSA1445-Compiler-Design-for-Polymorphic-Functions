#include <stdio.h>
#include <ctype.h>

int main() {
    char a[10];
    int i = 1;
    
    printf("Enter an identifier: ");
    gets(a);

    if (!isalpha(a[0])) {
        printf("Not a valid identifier");
        return 0;
    }

    while (a[i] && (isalnum(a[i]))) i++;

    printf(a[i] ? "Not a valid identifier" : "Valid identifier");
    return 0;
}
