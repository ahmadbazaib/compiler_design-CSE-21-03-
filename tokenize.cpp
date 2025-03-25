#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a character is a delimiter
bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
        ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || 
        ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return true;
    return false;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || 
        ch == '<' || ch == '=')
        return true;
    return false;
}

// Function to check if a string is a valid identifier
bool validIdentifier(char* str) {
    if (str[0] >= '0' && str[0] <= '9' || isDelimiter(str[0])) // Fixed condition
        return false;
    return true;
}

// Function to check if a string is a keyword
bool isKeyword(char* str) {
    char* keywords[] = {
        "if", "else", "while", "do", "break", "continue", "int", "double", 
        "float", "return", "char", "case", "sizeof", "long", "short", 
        "typedef", "switch", "unsigned", "void", "static", "struct", "goto"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (!strcmp(str, keywords[i]))
            return true;
    }
    return false;
}

// Function to check if a string is an integer
bool isInteger(char* str) {
    int i, len = strlen(str);
    if (len == 0) return false;
    
    for (i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && i > 0))
            return false;
    }
    return true;
}

// Function to check if a string is a real number
bool isRealNumber(char* str) {
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0) return false;

    for (i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' || 
            (str[i] == '-' && i > 0))
            return false;
        if (str[i] == '.') hasDecimal = true;
    }
    return hasDecimal;
}

// Function to extract a substring
char* subString(char* str, int left, int right) {
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return subStr;
}

// Function to tokenize and classify tokens in a string
void parse(char* str) {
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right) {
        if (!isDelimiter(str[right]))
            right++;

        if (isDelimiter(str[right]) && left == right) {
            if (isOperator(str[right]))
                printf("'%c' IS AN OPERATOR\n", str[right]);

            right++;
            left = right;
        } 
        else if ((isDelimiter(str[right]) && left != right) || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);

            if (isKeyword(subStr))
                printf("'%s' IS A KEYWORD\n", subStr);
            else if (isInteger(subStr))
                printf("'%s' IS AN INTEGER\n", subStr);
            else if (isRealNumber(subStr))
                printf("'%s' IS A REAL NUMBER\n", subStr);
            else if (validIdentifier(subStr) && !isDelimiter(str[right - 1]))
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
            else if (!validIdentifier(subStr) && !isDelimiter(str[right - 1]))
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);

            left = right;
        }
    }
}

int main() {
    char str[100] = "int var = 5.4, x;";
    parse(str);
    return 0;
}
