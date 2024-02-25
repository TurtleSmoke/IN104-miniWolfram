#include "tests_utils.h"

TEST(Eval, basic1) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = NUMBER, .value = 2},
                {.type = ADD, .value = 0},
            },
        .length = 3,
    };
    int actual = Eval(&input);
    int expected = 3;
    assert(actual == expected);
}

TEST(Eval, basic2) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = NUMBER, .value = 2},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 3},
                {.type = SUB, .value = 0},
            },
        .length = 5,
    };
    int actual = Eval(&input);
    int expected = 0;
    assert(actual == expected);
}

TEST(Eval, basic3) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = NUMBER, .value = 2},
                {.type = NUMBER, .value = 3},
                {.type = MUL, .value = 0},
                {.type = ADD, .value = 0},
            },
        .length = 5,
    };
    int actual = Eval(&input);
    int expected = 7;
    assert(actual == expected);
}