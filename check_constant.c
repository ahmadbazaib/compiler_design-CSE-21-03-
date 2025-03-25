#include <stdio.h>
#include <ctype.h>

int isIntegerConstant(char *str) {
    int i = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;

    while (str[i] != '\0') {
        if (!isdigit(str[i])) 
            return 0;
        i++;
    }

    return (i > 0 && str[i-1] != '+' && str[i-1] != '-') ? 1 : 0;
}

int main() {
    char input[50];

    printf("Enter a number: ");
    scanf("%s", input);

    if (isIntegerConstant(input))
        printf("\"%s\" is a valid integer constant.\n", input);
    else
        printf("\"%s\" is NOT a valid integer constant.\n", input);

    return 0;
}
