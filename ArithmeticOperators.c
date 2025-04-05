#include<stdio.h>
int main() {
    char s[3];
    printf("Enter any operator: ");
    gets(s);
    switch (s[0]) {
        case '>': printf(s[1] == '=' ? "Greater than or equal" : "Greater than"); break;
        case '<': printf(s[1] == '=' ? "Less than or equal" : "Less than"); break;
        case '=': printf(s[1] == '=' ? "Equal to" : "Assignment"); break;
        case '!': printf(s[1] == '=' ? "Not Equal" : "Bit Not"); break;
        case '&': printf(s[1] == '&' ? "Logical AND" : "Bitwise AND"); break;
        case '|': printf(s[1] == '|' ? "Logical OR" : "Bitwise OR"); break;
        case '+': printf("Addition"); break;
        case '-': printf("Subtraction"); break;
        case '*': printf("Multiplication"); break;
        case '/': printf("Division"); break;
        case '%': printf("Modulus"); break;
        default: printf("Not an operator");
    }
}
