#include "help_func.h"

#include <stdio.h>

int main() {
    char program[STACK_MAX];
    const char* file_name = "program.txt";

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    fread(program, sizeof(char), file_size, file);
    fclose(file);

    int answer = is_balanced(program);
    check(answer);
    return 0;
}
