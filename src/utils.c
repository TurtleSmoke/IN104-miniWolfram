#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int TokenPrecedence(Token token) {
    if (token.type == NUMBER) {
        fprintf(stderr, "Tried to get precedence of number\n");
        exit(1);
    }
    int precedences[] = {-1, 0, 0, 1, 1, 1, 2, 2};
    return precedences[token.type];
}

TokenStack CreateTokenStack(void) {
    TokenStack token_stack;
    for (int i = 0; i < MAX_TOKENS; i++) {
        Token token = {0, 0};
        token_stack.tokens[i] = token;
    }
    token_stack.length = 0;
    return token_stack;
}

void PushTokenStack(TokenStack *stack, Token token) {
    if (stack->length == MAX_TOKENS) {
        fprintf(stderr, "Tried to push to full stack\n");
        exit(1);
    }
    stack->tokens[stack->length++] = token;
}

Token PopTokenStack(TokenStack *stack) {
    if (stack->length == 0) {
        fprintf(stderr, "Tried to pop from empty stack\n");
        exit(1);
    }
    return stack->tokens[--stack->length];
}

Token PeekTokenStack(TokenStack *stack) {
    if (stack->length == 0) {
        fprintf(stderr, "Tried to peek from empty stack\n");
        exit(1);
    }
    return stack->tokens[stack->length - 1];
}

int IsEmptyTokenStack(TokenStack *stack) {
    return stack->length == 0;
}

TokenQueue CreateTokenQueue(void) {
    TokenQueue token_array;
    for (int i = 0; i < MAX_TOKENS; i++) {
        Token token = {0, 0};
        token_array.tokens[i] = token;
    }
    token_array.length = 0;
    return token_array;
}

void AppendTokenQueue(TokenQueue *array, Token token) {
    if (array->length == MAX_TOKENS) {
        fprintf(stderr, "Tried to append to full array\n");
        exit(1);
    }
    array->tokens[array->length++] = token;
}

Token PopTokenQueue(TokenQueue *array) {
    if (array->length == 0) {
        fprintf(stderr, "Tried to pop from empty array\n");
        exit(1);
    }
    Token res = array->tokens[0];
    for (int i = 0; i < array->length - 1; i++) {
        array->tokens[i] = array->tokens[i + 1];
    }
    array->length--;
    return res;
}

int IsEmptyTokenQueue(TokenQueue *array) {
    return array->length == 0;
}

void ReverseTokenQueue(TokenQueue *array) {
    for (int i = 0; i < array->length / 2; i++) {
        Token temp = array->tokens[i];
        array->tokens[i] = array->tokens[array->length - i - 1];
        array->tokens[array->length - i - 1] = temp;
    }
}

void PrintTokenArray(TokenQueue *tokens) {
    const char *TokenTypeStrings[] = {
        "NUMBER", "+", "-", "*", "/", "%", "(", ")",
    };
    for (int i = 0; i < tokens->length; i++) {
        Token token = tokens->tokens[i];
        if (token.type == NUMBER) {
            printf("%d", token.value);
        } else {
            printf("%s", TokenTypeStrings[token.type]);
        }
    }
    printf("\n");
}
