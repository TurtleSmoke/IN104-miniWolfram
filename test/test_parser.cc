#include "tests_utils.h"

TEST(Parser, basic1) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
            },
        .length = 3,
    };
    TokenQueue actual = Parse(&input);
    TokenQueue expected = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = NUMBER, .value = 2},
                {.type = ADD, .value = 0},
            },
        .length = 3,
    };
    areTokenQueuesEqual(actual, expected);
}

TEST(Parser, basic2) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
                {.type = SUB, .value = 0},
                {.type = NUMBER, .value = 3},
            },
        .length = 5,
    };
    TokenQueue actual = Parse(&input);
    TokenQueue expected = {
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
    areTokenQueuesEqual(actual, expected);
}

TEST(Parser, basic3) {
    TokenQueue input = {
        .tokens =
            {
                {.type = NUMBER, .value = 1},
                {.type = ADD, .value = 0},
                {.type = NUMBER, .value = 2},
                {.type = MUL, .value = 0},
                {.type = NUMBER, .value = 3},
            },
        .length = 5,
    };
    TokenQueue actual = Parse(&input);
    TokenQueue expected = {
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
    areTokenQueuesEqual(actual, expected);
}