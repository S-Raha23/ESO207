#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int size;
    int *arr;
    int top;
};

// Initialize stack
void initStack(struct Stack *ptr, int size) {
    ptr->top = -1;
    ptr->size = size;
    ptr->arr = (int *)malloc(size * sizeof(int));
}

// Check if stack is empty
bool isEmpty(struct Stack *ptr) {
    return ptr->top == -1;
}

// Push value onto stack
void push(struct Stack *ptr, int val) {
    if (ptr->top >= ptr->size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    ptr->arr[++ptr->top] = val;
}

// Pop value from stack and return it
int pop(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow\n");
        return -1; // Error value
    }
    return ptr->arr[ptr->top--];
}

// Peek top value of stack
int peek(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        return -1; // Error value
    }
    return ptr->arr[ptr->top];
}

// Compute power function
int power(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int val = power(a, b / 2);
    return (b % 2 == 0) ? val * val : val * val * a;
}

// Get precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Higher precedence for exponentiation
    return 0; // For '('
}

// Apply an operation
int applyOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            printf("Error: Division by zero\n");
            exit(1);
        }
        return a / b;
    }
    if (op == '^') return power(a, b);
    return 0;
}

// Evaluate an expression
int evaluate(char *str) {
    struct Stack numStack, opStack;
    initStack(&numStack, MAX);
    initStack(&opStack, MAX);

    int i = 0;
    while (str[i] != '\0') {
        // Skip spaces
        if (isspace(str[i])) {
            i++;
            continue;
        }

        // Handle negative numbers at the start or after '('
        if (str[i] == '-' && (i == 0 || str[i - 1] == '(')) {
            i++;
            int val = 0;
            while (isdigit(str[i])) {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            push(&numStack, -val);
            continue;
        }

        // If it's a number, parse and push to numStack
        if (isdigit(str[i])) {
            int val = 0;
            while (isdigit(str[i])) {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            push(&numStack, val);
            continue;
        }

        // If it's an opening bracket, push to operator stack
        if (str[i] == '(') {
            push(&opStack, str[i]);
        }
        // If it's a closing bracket, solve entire bracket expression
        else if (str[i] == ')') {
            while (!isEmpty(&opStack) && peek(&opStack) != '(') {
                int b = pop(&numStack);
                int a = pop(&numStack);
                char op = pop(&opStack);
                push(&numStack, applyOperation(a, b, op));
            }
            pop(&opStack); // Remove '('
        }
        // If it's an operator
        else {
            while (!isEmpty(&opStack) && precedence(peek(&opStack)) >= precedence(str[i])) {
                int b = pop(&numStack);
                int a = pop(&numStack);
                char op = pop(&opStack);
                push(&numStack, applyOperation(a, b, op));
            }
            push(&opStack, str[i]);
        }
        i++;
    }

    // Process remaining operations
    while (!isEmpty(&opStack)) {
        int b = pop(&numStack);
        int a = pop(&numStack);
        char op = pop(&opStack);
        push(&numStack, applyOperation(a, b, op));
    }

    return peek(&numStack);
}

// Main function
int main() {
    char expression[MAX];
    printf("Enter expression: ");
    scanf("%s", expression);
    
    int result = evaluate(expression);
    printf("Result: %d\n", result);
    return 0;
}
