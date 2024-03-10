#include <stdio.h>

#include "eval.h"
#include "lexer.h"
#include "parser.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: miniWolfram <equation>\n");
        return 1;
    }
    TokenQueue tokens = Lex(argv[1]);
    TokenQueue output = Parse(&tokens);
    int result = Eval(&output);
    printf("%d\n", result);

    return 0;
}
