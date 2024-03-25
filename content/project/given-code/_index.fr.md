+++
title = "Fichiers fournis"
pre = "<b>3. </b>"
weight = 15
+++

## Fichiers fournis

Pour vous aider à démarrer, nous avons fourni un fichier utilitaire contenant les structures suivantes :

- [TokenType](#token-types) : Une énumération représentant les différents types de jetons.
- [Token](#token-structure) : Une structure représentant un jeton.
- [TokenQueue](#token-queue-structure) : Une structure représentant une file de jetons.
- [TokenStack](#token-stack-structure) : Une structure représentant une pile de jetons.

## Token types

L'énumération `TokenType` contient les types de jetons suivants :

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

Vous pouvez utiliser cette énumération pour identifier le type de chaque jeton dans la chaîne d'entrée. Vous pouvez
également ajouter ou supprimer des types de jetons selon vos besoins.

## Token structure

La structure `Token` contient les champs suivants :

```c
typedef struct {
    TokenType type;
    int value;
} Token;
```

Cette structure représente un jeton, qui est un élément unique de la chaîne d'entrée. Elle contient un champ `type` pour
identifier le type du jeton et un champ `value` pour stocker la valeur du jeton s'il s'agit d'un nombre.

La structure de jeton peut être utilisée comme suit :

```c
Token token1 = {NUMBER, 42};
Token token2;
token2.type = ADD;
token2.value = 0
```

## Token queue structure

La structure `TokenQueue` contient les champs suivants :

```c
typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenQueue;
```

Cette structure représente une file de jetons. Elle contient un tableau de jetons et un champ `length` pour stocker le
nombre de jetons actuellement dans la file.

De plus, la structure `TokenQueue` inclut les fonctions suivantes :

```c
TokenQueue CreateTokenQueue(void); // Crée une file de jetons vide
void AppendTokenQueue(TokenQueue *array, Token token); // Ajoute un jeton à la fin de la file
Token PopTokenQueue(TokenQueue *array); // Supprime et renvoie le premier jeton de la file
int IsEmptyTokenQueue(TokenQueue *array); // Vérifie si la file est vide
void ReverseTokenQueue(TokenQueue *array); // Inverse l'ordre des jetons dans la file
void PrintTokenQueue(TokenQueue *tokens); // Affiche les jetons dans la file
```

Voici un exemple d'utilisation de la structure `TokenQueue` :

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

La structure `TokenStack` contient les champs suivants :

```c
typedef struct {
    Token tokens[MAX_TOKENS];
    int length;
} TokenStack;
```

La structure est très similaire à la structure `TokenQueue`, mais fonctionne comme une pile plutôt qu'une file. Elle
inclut également la plupart des fonctions présentées dans la structure `TokenQueue`.

Voici un exemple d'utilisation de la structure `TokenStack` :

```c
Token token1 = {NUMBER, 42};
Token token2 = {ADD, 0};
Token token3 = {NUMBER, 24};

TokenStack stack = CreateTokenStack();
PushTokenStack(&stack, token1);
PushTokenStack(&stack, token2);
PushTokenStack(&stack, token3);
PrintTokenStack(&stack);
// 24+42

Token token4 = PeekTokenStack(&stack);
printf("Peek: %d\n", token4.value);
// Peek: 24

Token token5 = PopTokenStack(&stack);
PrintTokenStack(&stack);
// +42

printf("Is empty: %d\n", IsEmptyTokenStack(&stack));
// Is empty: 0
PopTokenStack(&stack);
PopTokenStack(&stack);
printf("Is empty: %d\n", IsEmptyTokenStack(&stack));
// Is empty: 1
```

{{% notice note %}}
Vous êtes libre d'ajouter, de modifier ou de supprimer toutes les structures et fonctions fournies selon vos besoins.
{{% /notice %}}
