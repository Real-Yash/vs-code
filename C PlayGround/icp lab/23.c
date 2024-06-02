#include <stdio.h>

int main() {
    int array1[3][3], array2[3][3], diff[3][3];
    int i, j;

    printf("Enter elements of the first 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    printf("\nEnter elements of the second 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    // Subtracting Two matrices

    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j) {
            diff[i][j] = array1[i][j] - array2[i][j];
        }

    // Displaying the resultant difference matrix.

    printf("\nDifference of the two matrices: \n");

    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j) {
            printf("%d   ", diff[i][j]);
            if(j == 2)
                printf("\n\n");
        }

    return 0;
}
