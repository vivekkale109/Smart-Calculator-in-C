#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// ---------- STACKS ----------
char opStack[MAX];
int top = -1;

double valStack[MAX];
int valTop = -1;

void pushOp(char op) { opStack[++top] = op; }
char popOp() { return opStack[top--]; }
char peekOp() { return opStack[top]; }

void pushVal(double val) { valStack[++valTop] = val; }
double popVal() { return valStack[valTop--]; }

// ---------- PRECEDENCE ----------
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ---------- APPLY OP ----------
double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        case '^': return pow(a, b);
    }
    return 0;
}