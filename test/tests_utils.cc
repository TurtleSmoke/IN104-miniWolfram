#include "tests_utils.h"

void areTokenQueuesEqual(TokenQueue actual, TokenQueue expected) {
    ASSERT_EQ(actual.length, expected.length);
    for (int i = 0; i < actual.length; i++) {
        ASSERT_EQ(actual.tokens[i].type, expected.tokens[i].type);
        if (expected.tokens[i].type == NUMBER) {
            ASSERT_EQ(actual.tokens[i].value, expected.tokens[i].value);
        }
    }
}
