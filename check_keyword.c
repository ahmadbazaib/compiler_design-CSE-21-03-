#include <stdio.h>
#include <string.h>

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

int main() {
    char input[100];

    printf("Enter a word: ");
    scanf("%s", input);

    if (isKeyword(input))
        printf("\"%s\" is a valid C keyword.\n", input);
    else
        printf("\"%s\" is NOT a valid C keyword.\n", input);

    return 0;
}
