#include <stdio.h>

int main() {
    int num1, num2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

        // Check if the numbers are the same
    if(num1 == num2) {
        printf("Error: Both numbers are the same.\n");
        return 1; // Return an error code
    }
    
    // Using conditional operator to find the maximum number
    max = (num1 > num2) ? num1 : num2;

    printf("Maximum between %d and %d is %d", num1, num2, max);

    return 0;
}
