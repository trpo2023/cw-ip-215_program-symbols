#include "help_func.h"

#include <stdio.h>

int main() {
    char program[STACK_MAX];
    printf("Enter a program: ");
    fgets(program, STACK_MAX, stdin);
    int answer = is_balanced(program);
    check(answer);
    return 0;
}
