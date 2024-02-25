#ifndef MINIWOLFRAM_UTILS_H
#define MINIWOLFRAM_UTILS_H

#define MAX_TOKENS 100

typedef enum {
    NUMBER = 0,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    LEFT_PAREN,
    RIGHT_PAREN,
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenQueue;

typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenStack;

int TokenPrecedence(Token token);

// Create an empty token stack
TokenStack CreateTokenStack(void);
// Push to the end
void PushTokenStack(TokenStack *stack, Token token);
// Pop from the end
Token PopTokenStack(TokenStack *stack);
Token PeekTokenStack(TokenStack *stack);
// 1 if empty, 0 if not empty
int IsEmptyTokenStack(TokenStack *stack);

// Create an empty token array
TokenQueue CreateTokenQueue(void);
// Append to the end
void AppendTokenQueue(TokenQueue *array, Token token);
// Pop from the end
Token PopTokenQueue(TokenQueue *array);
// 1 if empty, 0 if not empty
int IsEmptyTokenQueue(TokenQueue *array);
// Reverse the token array
void ReverseTokenQueue(TokenQueue *array);

void PrintTokenArray(TokenQueue *tokens);

#endif  // MINIWOLFRAM_UTILS_H
