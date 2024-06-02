#include <stdio.h>

int main() {
    int num1, num2;
    char sign;

    // Prompt the user to enter the sign of the operation
    printf("Enter the sign of operation you want to perform (+, -, *, //):\n");

    // Use %c in scanf to read a character
    scanf(" %c", &sign);

    // Prompt the user to enter two numbers
    printf("Enter two numbers:\n");

    // Use %d in scanf to read integers
    scanf("%d %d", &num1, &num2);

    // Use a switch statement to perform the calculation based on the entered sign
    switch (sign) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;

        case '-':
            printf("Result: %d\n", num1 - num2);
            break;

        case '*':
            printf("result %d\n", num1 * num2);
            break;

            case '/':
            printf("result %d\n", num1 / num2);
            break;

        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}