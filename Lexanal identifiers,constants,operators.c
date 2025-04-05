#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char b[30], operators[10], identifiers[10], constants[10];
    int ic = 0, cc = 0, oc = 0, i, num;

    printf("Enter the string: ");
    scanf(" %[^\n]", b);

    for (i = 0; b[i]; i++) {
        if (isspace(b[i])) continue;
        if (isalpha(b[i])) identifiers[ic++] = b[i];
        else if (isdigit(b[i])) {
            num = 0;
            while (isdigit(b[i])) num = num * 10 + (b[i++] - '0');
            constants[cc++] = num;
            i--;
        } else if (strchr("+-*=", b[i])) operators[oc++] = b[i];
    }

    printf("Identifiers: %.*s\nConstants: ", ic, identifiers);
    for (i = 0; i < cc; i++) printf("%d ", constants[i]);
    printf("\nOperators: %.*s\n", oc, operators);

    return 0;
}
