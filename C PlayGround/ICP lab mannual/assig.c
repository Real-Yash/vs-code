#include <stdio.h>

int main() {
    int n, num, largest, smallest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number of elements.\n");
        return 1;
    }

    printf("Enter element 1: ");
    scanf("%d", &num);

    largest = smallest = num;

    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &num);

        if (num > largest) {
            largest = num;
        }

        if (num < smallest) {
            smallest = num;
        }
    }

    printf("Largest number is %d\n", largest);
    printf("Smallest number is %d\n", smallest);

    return 0;
}