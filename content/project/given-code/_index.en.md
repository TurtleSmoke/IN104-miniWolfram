+++
title = "Provided files"
weight = 15
+++

## Provided files

To help you get started, we have provided a utils file containing the following structures:

- [TokenType](#token-types): An enumeration representing the different types of tokens.
- [Token](#token-structure): A structure representing a token.
- [TokenQueue](#token-queue-structure): A structure representing a queue of tokens.
- [TokenStack](#token-stack-structure): A structure representing a stack of tokens.

## Token types

The `TokenType` enumeration contains the following token types:

```c
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
```

You can use this enumeration to identify the type of each token in the input string. You can also add or remove token
types as needed.

## Token structure

The `Token` structure contains the following fields:

```c
typedef struct {
    TokenType type;
    int value;
} Token;
```

This structure represents a token, which is a single element of the input string. It contains a `type` field to identify
the type of the token and a `value` field to store the value of the token if it is a number.

The token structure can be used as follows:

```c
Token token1 = {NUMBER, 42};
Token token2;
token2.type = ADD;
token2.value = 0
```

## Token queue structure

The `TokenQueue` structure contains the following fields:

```c
typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenQueue;
```

This structure represents a queue of tokens. It contains an array of tokens and a `length` field to store the number of
tokens currently in the queue.

Furthermore, the `TokenQueue` structure includes the following functions:

```c
TokenQueue CreateTokenQueue(void); // Create an empty token queue
void AppendTokenQueue(TokenQueue *array, Token token); // Append a token to the end of the queue
Token PopTokenQueue(TokenQueue *array); // Remove and return the first token in the queue
int IsEmptyTokenQueue(TokenQueue *array); // Check if the queue is empty
void ReverseTokenQueue(TokenQueue *array); // Reverse the order of the tokens in the queue
void PrintTokenQueue(TokenQueue *tokens); // Print the tokens in the queue
```

Here is an example of how to use the `TokenQueue` structure:

```c
Token token1 = {NUMBER, 42};
Token token2 = {ADD, 0};
Token token3 = {NUMBER, 24};

TokenQueue queue = CreateTokenQueue();
AppendTokenQueue(&queue, token1);
AppendTokenQueue(&queue, token2);
AppendTokenQueue(&queue, token3);
PrintTokenQueue(&queue);
// 42+24

Token token = PopTokenQueue(&queue);
PrintTokenQueue(&queue);
// +24

ReverseTokenQueue(&queue);
PrintTokenQueue(&queue);
// 24+

printf("Is empty: %d\n", IsEmptyTokenQueue(&queue));
// Is empty: 0
PopTokenQueue(&queue);
PopTokenQueue(&queue);
IsEmptyTokenQueue(&queue);
printf("Is empty: %d\n", IsEmptyTokenQueue(&queue));
// Is empty: 1
```

## Token stack structure

The `TokenStack` structure contains the following fields:

```c
typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenStack;
```

The structure is very similar to the `TokenQueue` structure, but functions as a stack rather than a queue. It also
includes most of the functions presented in the `TokenQueue` structure.

Here is an example of how to use the `TokenStack` structure:

```c
Token token1 = {NUMBER, 42};
Token token2 = {ADD, 0};
Token token3 = {NUMBER, 24};

TokenStack stack = CreateTokenStack();
PushTokenStack(&stack, token1);
PushTokenStack(&stack, token2);
PushTokenStack(&stack, token3);
PrintTokenStack(&stack);
// 42+24

Token token = PopTokenStack(&stack);
PrintTokenStack(&stack);
// 42+

printf("Is empty: %d\n", IsEmptyTokenStack(&stack));
// Is empty: 0
PopTokenStack(&stack);
PopTokenStack(&stack);
printf("Is empty: %d\n", IsEmptyTokenStack(&stack));
// Is empty: 1
```

{{% notice note %}}
You are free to add, modify, or remove any of the provided structures and functions as needed.
{{% /notice %}}
