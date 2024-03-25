+++
title = "Description"
pre = "<b>2. </b>"
weight = 10
+++

{{% notice note %}}
Before starting the project, please follow the instructions in the [first step](project/first-step) to download the
provided files and create a new repository.
{{% /notice %}}

## Overview

The project is focused on creating a simplified version of [Wolfram Alpha](https://www.wolframalpha.com/) starting with
the implementation of a basic calculator. This baseline calculator must be capable of handling the following operations:

- Addition
- Subtraction
- Multiplication
- Division
- Modulus

Additionally, the calculator must handle parentheses and spaces within expressions.

Your executable must be named `miniWolfram` and must accept a mathematical expression as a command-line argument.
Upon execution, the program should evaluate the expression and print the result to the standard output. Any error
messages should be printed to the standard error.

Here are examples illustrating the expected behavior of the program:

```shell
./miniWolfram "1 + 1"
2

./miniWolfram "1 + 2 * 3"
7

./miniWolfram "(1 + 2) * 3"
9

./miniWolfram "1       + 1"
2
```

{{% notice note %}}
The provided code includes helpful functions to help you get started. Please refer to [this link](project/given-code)
for more details.
{{% /notice %}}

## Project guidelines

The project is divided into three parts:

- [Lexical analysis](#lexical-analysis)
- [Syntax analysis](#syntax-analysis)
- [Evaluation](#evaluation)

Each part is described in detail in the following sections.

### Lexical analysis

The lexical analysis is the first step of the project. It converts the input string into a sequence of tokens, where
each token represents a single element of the input string, such as a number, an operator, or a parenthesis. This step
also includes the detection of invalid tokens such as letters or special characters.

The program that performs lexical analysis is called a lexer. By using a lexer, you will be able to focus on the syntax
and the evaluation of the expression without worrying about the lexical correctness of the input.

### Syntax analysis

The syntax analysis is the second step of the project. It converts a sequence of tokens into a Reverse Polish Notation
(RPN) expression. This process also includes the detection of invalid expressions such as missing operators or operands.

The [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) is a mathematical notation in which
every operator follows all of its operands, it removes the ambiguity of operation priority in the commonly used
notation (called infix notation). It makes the evaluation of the expression easier and removes the need for parentheses.
For example, the expression `1 + 2 * 3` is represented by the following RPN expression: `1 2 3 * +`.

You are free to use any algorithm to convert the infix expression into RPN, but you are advised to use the
[Shunting-yard algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm), as the pseudocode is provided in the
Wikipedia page and can be easily adapted to your needs.

### Evaluation

The evaluation is the last step of the project. It consists of evaluating the RPN expression resulting from the syntax
analysis. The RPN expression can be visualized as a binary tree, where the leaves are the numbers and the internal nodes
are the operators. Using the previous RPN expression as an example, we get the following binary tree:

{{< mermaid >}}
graph TD
A((+)) --> B((1))
A --> C((*))
C --> D((2))
C --> E((3))
{{< /mermaid >}}

This tree can be evaluated using [post-order traversal](https://en.wikipedia.org/wiki/Tree_traversal#Post-order,_LRN).
You are free to use any algorithm to evaluate the RPN expression, whether it is a recursive algorithm, a stack-based, or
a tree-based algorithm.

### To go further

Once the baseline calculator is operational, you are encouraged to enhance it by integrating additional features of your
choice.
Here are a few examples of additional features, but you are invited to come up with your own great ideas:

- Functions (sin, cos, tan, log, etc.)
- Constants (pi, e, etc.)
- Variables, including the ability to store and retrieve values
- Graphical user interface
- Step-by-step resolution
- Equation solving (linear, quadratic, etc.)
- Plotting graph from linear or quadratic equations
- Integration and differentiation
- Matrices calculations
- Handling of complex numbers
- Handling of infinite numbers of tokens

## Overview of the project

As a picture is worth a thousand words, here is an overview of the input and output of each step of the project:

![Project overview](overview.png?width=100%^&height=100%)