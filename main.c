#include <stdio.h>

#define STACK_MAX 1000

typedef struct {
    int top;
    char data[STACK_MAX];
} Stack;

void push(Stack* stack, char c) {
    if (stack->top < STACK_MAX) {
        stack->data[stack->top] = c;
        stack->top++;
    }
    else {
        printf("Stack overflow\n");
    }
}

char pop(Stack* stack) {
    if (stack->top > 0) {
        stack->top--;
        return stack->data[stack->top];
    }
    else {
        return '\0';
    }
}

int is_balanced(char* program) {
    Stack stack = { 0 };
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
        printf("Balanced\n");
        return 1;
    }
    else {
        printf("You have mistake\n");
        return 0;
    }
}


int main()
{
    char program[STACK_MAX];
    printf("Enter a program: ");
    fgets(program, STACK_MAX, stdin);
    int answer = is_balanced(program);
    check(answer);
    return 0;
}
