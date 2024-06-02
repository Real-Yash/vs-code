#include <stdio.h>

int main() {
    int array[3][3], transpose[3][3];
    int i, j;

    printf("Enter elements of the 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Finding the transpose of matrix array
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            transpose[j][i] = array[i][j];
        }

    printf("\nTranspose of the matrix:\n");

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            printf("%d  ", transpose[i][j]);
            if(j == 2)
                printf("\n\n");
        }

    return 0;
}
