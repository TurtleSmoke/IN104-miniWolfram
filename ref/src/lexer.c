#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

Token getToken(char **input) {
    if (**input >= '0' && **input <= '9') {
        int value = 0;
        while (**input >= '0' && **input <= '9') {
            value = value * 10 + (**input - '0');
            (*input)++;
        }
        return (Token){NUMBER, value};
    } else {
        int tokens[] = {'+', '-', '*', '/', '%', '(', ')'};
        TokenType types[] = {ADD, SUB, MUL, DIV, MOD, LEFT_PAREN, RIGHT_PAREN};
        for (int i = 0; i < 7; i++) {
            if (**input == tokens[i]) {
                (*input)++;
                return (Token){types[i], 0};
            }
        }
    }

    fprintf(stderr, "Invalid character: '%c'\n", **input);
    exit(1);
}

TokenQueue Lex(char *input) {
    TokenQueue token_array = CreateTokenQueue();
    while (*input != '\0') {
        while (*input == ' ') {
            input++;
        }
        if (*input == '\0') {
            break;
        }
        Token token = getToken(&input);
        AppendTokenQueue(&token_array, token);
    }
    return token_array;
}
