#include "help_func.h"

#include <stdio.h>

void push(Stack* stack, char c)
{
    if (stack->top < STACK_MAX) {
        stack->data[stack->top] = c;
        stack->top++;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack* stack)
{
    if (stack->top > 0) {
        stack->top--;
        return stack->data[stack->top];
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

int is_balanced(char* program)
{
    Stack stack = {0};
    for (int i = 0; program[i] != '\0'; i++) {
        char c = program[i];
        switch (c) {
        case '(':
        case '{':
        case '[':
            push(&stack, c);
            break;
        case ')':
            if (pop(&stack) != '(') {
                return 0;
            }
            break;
        case '}':
            if (pop(&stack) != '{') {
                return 0;
            }
            break;
        case ']':
            if (pop(&stack) != '[') {
                return 0;
            }
            break;
        default:
            break;
        }
    }
    return stack.top == 0;
}

int check(int answer)
{
    if (answer) {
        printf("balanced\n");
        return 1;
    } else {
        printf("You have mistake\n");
        return 0;
    }
}
