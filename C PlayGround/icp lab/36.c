#include <stdio.h>

void function1() {
    printf("This is function1\n");
}

void function2() {
    printf("This is function2\n");
}

void function3() {
    printf("This is function3\n");
}

int main() {
    void (*array_of_function_pointers[3])() = {function1, function2, function3};

    for(int i = 0; i < 3; i++) {
        array_of_function_pointersi;
    }

    return 0;
}
