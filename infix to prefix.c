#include <stdio.h>
#include <ctype.h>

int top = -1, top1 = -1;
char stack[1000], op_stack[1000], expr[] = "(a+b)*c+d/(e-f)";

void push(char n) {
    stack[++top] = n;
}

void op_push(char n) {
    op_stack[++top1] = n;
}

char op_pop() {
    return op_stack[top1--];
}

int isoperator(char ch) {
    return (ch == '^' || ch == '%' || ch == '/' || ch == '*' || ch == '+' || ch == '-' || ch == '(' || ch == ')');
}

int precedence(char ch) {
    switch(ch) {
        case '^': return 4;
        case '%': return 3;
        case '/': return 3;
        case '*': return 3;
        case '+': return 2;
        case '-': return 2;
        case '(': return 1;
        case ')': return 1;
        default: return -1;
    }
}

int string_length() {
    int i = 0;
    while (expr[i] != '\0') {
        i++;
    }
    return i;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

void process_operator(char ch) {
    while (top1 != -1 && precedence(op_stack[top1]) > precedence(ch) && op_stack[top1] != '(') {
        push(op_pop());
    }
    op_push(ch);
}

int main() {
    for (int i = string_length()-1; i >= 0; i--) {
        char ch = expr[i];
        if (isoperator(ch)) {
            if (ch == ')') {
                op_push(ch);
            } else if (ch == '(') {
                while (op_stack[top1] != ')') {
                    push(op_pop());
                }
                op_pop();
            } else {
                process_operator(ch);
            }
        } else {
            push(ch);
        }
    }
    
    while (top1 != -1) {
        push(op_pop());
    }

    display();
    return 0;
}