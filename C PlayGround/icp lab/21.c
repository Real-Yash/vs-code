#include <stdio.h>

int main() {
    int array[3][3]; // Declare a 3x3 array
    int i, j;

    printf("Enter elements of the 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("\nDisplaying elements of the 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
