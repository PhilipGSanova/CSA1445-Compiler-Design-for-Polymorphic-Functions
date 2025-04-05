#include <stdio.h>
int main() {
    char str[100];
    int words = 1, lines = 1, chars = 0;
    
    scanf("%[^~]", str); // Input until '~'
    
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') words++;
        else if (str[i] == '\n') { lines++; words++; }
        else chars++;
    }
    
    if (chars == 0) words = lines = 0; // Handle empty input case
    
    printf("Words: %d\nLines: %d\nCharacters: %d\n", words, lines, chars);
    return 0;
}
