# [IN104] 

This repository contains the reference to the project of the course IN104 at ENSTA.

## Project

The project is about the implementation of a simple calculator.
The calculator must be able to perform the following operations:
- Addition
- Subtraction
- Multiplication
- Division
- Modulus
- Parentheses

The calculator must be able to handle positive integers numbers.

## Implementation

The calculator should be implemented in C.
The implementation is free, but we advise to follow the following steps:
- Implement the lexer, which should be able to tokenize the input string.
- Implement the parser, which should be able to build an RPN expression from the tokenized input string.
- Implement the evaluator, which should be able to evaluate the RPN expression.

No matter the implementation, the calculator should be able to handle the following input:
```
./miniWolfram "<equation>"
```

## Example

Here is some examples of input and output:

```sh
./miniWolfram "1 + 1"
2
./miniWolfram "1 + 2 * 3"
7
./miniWolfram "(1 + 2) * 3"
9
./miniWolfram "1       + 1"
2
```

In case of error, the calculator should print an error message on the standard error output.
The error message should be explicit but will not be tested.

```
./miniWolfram "1 +" > /dev/null
Error: Invalid input: expression is not complete.
./miniWolfram "(1 + 2" > /dev/null
Error: Parsing error: Mismatched parentheses.
```
