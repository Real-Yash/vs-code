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
    // Example: To print a diamond pattern with size 5
    int size = 11;
    printDiamondPattern(size);

    return 0;
}
