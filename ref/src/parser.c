#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// Implement shunting yard algorithm
TokenQueue Parse(TokenQueue *tokens) {
    TokenQueue output = CreateTokenQueue();
    TokenStack stack = CreateTokenStack();

    while (!IsEmptyTokenQueue(tokens)) {
        Token token = PopTokenQueue(tokens);
        if (token.type == NUMBER) {
            AppendTokenQueue(&output, token);
        } else if (token.type == LEFT_PAREN) {
            PushTokenStack(&stack, token);
        } else if (token.type == RIGHT_PAREN) {
            while (PeekTokenStack(&stack).type != LEFT_PAREN) {
                AppendTokenQueue(&output, PopTokenStack(&stack));
            }
            if (IsEmptyTokenStack(&stack)) {
                fprintf(stderr, "Mismatched parentheses, too many right parentheses\n");
                exit(2);
            }
            PopTokenStack(&stack);
        } else {
            while (!IsEmptyTokenStack(&stack) && (PeekTokenStack(&stack).type != LEFT_PAREN) &&
                   (TokenPrecedence(token) < TokenPrecedence(PeekTokenStack(&stack)) ||
                    (TokenPrecedence(token) == TokenPrecedence(PeekTokenStack(&stack)) && token.type != LEFT_PAREN))) {
                AppendTokenQueue(&output, PopTokenStack(&stack));
            }
            PushTokenStack(&stack, token);
        }
    }

    while (!IsEmptyTokenStack(&stack)) {
        if (PeekTokenStack(&stack).type == LEFT_PAREN) {
            fprintf(stderr, "Mismatched parentheses\n");
            exit(2);
        }
        AppendTokenQueue(&output, PopTokenStack(&stack));
    }

    return output;
}
