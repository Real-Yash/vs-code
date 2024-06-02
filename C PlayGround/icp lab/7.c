#include <stdio.h>

int main() {
    int num1, num2, min;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Check if the numbers are the same
    if(num1 == num2) {
        printf("Error: Both numbers are the same.\n");
        return 1; // Return an error code
    }

    // Using conditional operator to find the minimum number
    min = (num1 < num2) ? num1 : num2;

    printf("Minimum between %d and %d is %d\n", num1, num2, min);

    return 0;
}

