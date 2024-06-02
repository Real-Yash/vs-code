#include <stdio.h>

int main() {
    int num1 = 1, num2 = 2, num3 = 3;
    int *array_of_pointers[3];

    array_of_pointers[0] = &num1;
    array_of_pointers[1] = &num2;
    array_of_pointers[2] = &num3;

    printf("Value of num1 = %d\n", *array_of_pointers[0]);
    printf("Value of num2 = %d\n", *array_of_pointers[1]);
    printf("Value of num3 = %d\n", *array_of_pointers[2]);

    return 0;
}
