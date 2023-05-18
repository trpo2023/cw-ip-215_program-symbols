#pragma once
#ifndef HELP_FUNC_H
#define HELP_FUNC_H

#define STACK_MAX 100

typedef struct {
    char data[STACK_MAX];
    int top;
} Stack;

void push(Stack* stack, char c);
char pop(Stack* stack);
int is_balanced(char* program);
int check(int answer);

#endif
