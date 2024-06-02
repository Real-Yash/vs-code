#include <stdio.h>

void printDiamondPattern(int n) {
    // Upper part of the diamond
    for (int i = 1; i <= n; i += 2) {
        int spaces = (n - i) / 2;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("\n");
    }

    // Lower part of the diamond
    for (int i = n - 2; i > 0; i -= 2) {
        int spaces = (n - i) / 2;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Get input from the user
    printf("Enter the size of the diamond: ");
    scanf("%d", &size);

    // Check if the size is odd
    if (size % 2 == 0) {
        printf("Please enter an odd number for the size of the diamond.\n");
        return 1; // Indicates an error
    }

    // Print the diamond pattern
    printDiamondPattern(size);

    return 0;
}
