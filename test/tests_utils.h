#include "gtest/gtest.h"

extern "C" {
#include "eval.h"
#include "lexer.h"
#include "parser.h"
#include "utils.h"
}

void areTokenQueuesEqual(TokenQueue actual, TokenQueue expected);
