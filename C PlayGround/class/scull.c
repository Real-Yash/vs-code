#include <stdio.h>

int main() {
    int rows;

    // Get the number of rows for the pattern
    printf("Enter the number of rows for the skull pattern: ");
    scanf("%d", &rows);

    // Create the skull pattern
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows; j++) {
            // Check conditions to determine whether to print 1 or 0 for the skull pattern
            if (((i == 1 || i == rows) && (j >= rows / 4 && j <= 3 * rows / 4)) ||
                ((i > 1 && i < rows / 2) && (j == rows / 4 || j == 3 * rows / 4)) ||
                ((i > rows / 2 && i < rows) && (j == 1 || j == rows))) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
