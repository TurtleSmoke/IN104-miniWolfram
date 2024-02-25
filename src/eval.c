#include "eval.h"

#include <stdio.h>
#include <stdlib.h>

int EvalRecursive(TokenQueue* tq, int* index) {
    if (*index == tq->length) {
        return 0;
    }

    Token token = tq->tokens[(*index)++];

    if (token.type == NUMBER) {
        return token.value;
    }

    int left = EvalRecursive(tq, index);
    int right = EvalRecursive(tq, index);

    switch (token.type) {
        case ADD:
            return left + right;
        case SUB:
            return left - right;
        case MUL:
            return left * right;
        case DIV:
            if (right == 0) {
                fprintf(stderr, "Division by zero\n");
                exit(1);
            }
            return left / right;
        case MOD:
            if (right == 0) {
                fprintf(stderr, "Division by zero\n");
                exit(1);
            }
            return left % right;
        default:
            fprintf(stderr, "Invalid token type\n");
            exit(1);
    }
}

int Eval(TokenQueue* tq) {
    int index = 0;
    ReverseTokenQueue(tq);
    return EvalRecursive(tq, &index);
}
