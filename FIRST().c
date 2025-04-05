#include <stdio.h>
#include <ctype.h>

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[10][10];

int main() {
    char c, choice, result[20];

    printf("Number of productions: ");
    scanf("%d", &numOfProductions);

    for (int i = 0; i < numOfProductions; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do {
        printf("\nFind FIRST of: ");
        scanf(" %c", &c);
        FIRST(result, c);

        printf("\nFIRST(%c) = { ", c);
        for (int i = 0; result[i]; i++)
            printf(" %c ", result[i]);
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void FIRST(char* Result, char c) {
    if (!isupper(c)) {
        addToResultSet(Result, c);
        return;
    }

    for (int i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == c) {
            if (productionSet[i][2] == '$') 
                addToResultSet(Result, '$');
            else {
                char subResult[20] = "";
                for (int j = 2, foundEpsilon; productionSet[i][j]; j++) {
                    FIRST(subResult, productionSet[i][j]);
                    for (int k = 0; subResult[k]; k++)
                        addToResultSet(Result, subResult[k]);

                    foundEpsilon = 0;
                    for (int k = 0; subResult[k]; k++)
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    if (!foundEpsilon) break;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val) {
    for (int k = 0; Result[k]; k++)
        if (Result[k] == val) return;
    
    int len = 0;
    while (Result[len]) len++;
    Result[len] = val;
    Result[len + 1] = '\0';
}
