#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    char items[MAX_SIZE];
    int top;
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %c.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return stack->items[stack->top--];
}
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}
void infixToPostfix(const char* infix, char* postfix) {
    struct Stack operatorStack;
    initialize(&operatorStack);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char token = infix[i];
        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack);  // Pop '('
        } else {
            while (!isEmpty(&operatorStack) && precedence(token) <= precedence(operatorStack.items[operatorStack.top])) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }
        i++;
    }
    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);
    return 0;
}
