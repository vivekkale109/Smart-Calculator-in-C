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

// ---------- INFIX → POSTFIX ----------
void infixToPostfix(char* exp, char* output) {
    int i, k = 0;
    top = -1;

    for(i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            while (isdigit(exp[i]) || exp[i] == '.') {
                output[k++] = exp[i++];
            }
            output[k++] = ' ';
            i--;
        }
        else if (exp[i] == '(') {
            pushOp(exp[i]);
        }
        else if (exp[i] == ')') {
            while (top != -1 && peekOp() != '(') {
                output[k++] = popOp();
                output[k++] = ' ';
            }
            popOp();
        }
        else if (strchr("+-*/^", exp[i])) {
            while (top != -1 && precedence(peekOp()) >= precedence(exp[i])) {
                output[k++] = popOp();
                output[k++] = ' ';
            }
            pushOp(exp[i]);
        }
    }

    while (top != -1) {
        output[k++] = popOp();
        output[k++] = ' ';
    }

    output[k] = '\0';
}

// ---------- POSTFIX EVALUATION ----------
double evaluatePostfix(char* exp) {
    int i;
    valTop = -1;

    for(i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            double num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            pushVal(num);
        }
        else if (strchr("+-*/^", exp[i])) {
            double b = popVal();
            double a = popVal();
            pushVal(applyOp(a, b, exp[i]));
        }
    }
    return popVal();
}

// ---------- SCIENTIFIC ----------
void scientificCalc() {
    int choice;
    double x;

    printf("\n1. sqrt\n2. sin\n3. cos\n4. log10\nChoice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%lf", &x);

    switch(choice) {
        case 1: printf("Result = %.2lf\n", sqrt(x)); break;
        case 2: printf("Result = %.2lf\n", sin(x)); break;
        case 3: printf("Result = %.2lf\n", cos(x)); break;
        case 4: printf("Result = %.2lf\n", log10(x)); break;
    }
}

// ---------- UNIT CONVERSION ----------
void unitConversion() {
    int choice;
    double val;

    printf("\n1. KM → M\n2. M → KM\n3. Inch → CM\nChoice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%lf", &val);

    switch(choice) {
        case 1: printf("Result = %.2lf m\n", val * 1000); break;
        case 2: printf("Result = %.2lf km\n", val / 1000); break;
        case 3: printf("Result = %.2lf cm\n", val * 2.54); break;
    }
}