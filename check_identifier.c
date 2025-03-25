#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

int isKeyword(char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int isValidIdentifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }

    if (isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char input[50];

    printf("Enter an identifier: ");
    scanf("%s", input);

    if (isValidIdentifier(input))
        printf("\"%s\" is a valid identifier.\n", input);
    else
        printf("\"%s\" is NOT a valid identifier.\n", input);

    return 0;
}
