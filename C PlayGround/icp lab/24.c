#include <stdio.h>

int main() {
    int array1[3][3], array2[3][3], product[3][3];
    int i, j, k;

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

    // Initializing elements of matrix product to 0.
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            product[i][j] = 0;
        }
    }

    // Multiplying matrix1 and matrix2 and storing in array product.
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            for(k = 0; k < 3; ++k) {
                product[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    printf("\nProduct of the two matrices: \n");

    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            printf("%d  ", product[i][j]);
            if(j == 2)
                printf("\n\n");
        }
    }

    return 0;
}
