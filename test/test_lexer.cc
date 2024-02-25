#include "tests_utils.h"

TEST(Lexer, basic1) {
    char input[] = "1 + 2";
    TokenQueue actual = Lex(input);
    TokenQueue expected = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
            },
        .length = 3,
    };
    areTokenQueuesEqual(actual, expected);
}

TEST(Lexer, basic2) {
    char input[] = "1 +             2";
    TokenQueue actual = Lex(input);
    TokenQueue expected = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
            },
        .length = 3,
    };
    areTokenQueuesEqual(actual, expected);
}

TEST(Lexer, basic3) {
    char input[] = "1 + 2 - 1";
    TokenQueue actual = Lex(input);
    TokenQueue expected = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
                {.type = SUB, .value = 0},
                {.type = NUMBER, .value = 1},
            },
        .length = 5,
    };
    areTokenQueuesEqual(actual, expected);
}
