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