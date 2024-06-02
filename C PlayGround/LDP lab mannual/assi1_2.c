#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int *array;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the entire 2D array in one go
    array = (int *)malloc(rows * cols * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input elements in the 2D array
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i * cols + j]);
        }
    }

    // Output elements in the 2D array
    printf("Elements in the array are:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i * cols + j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(array);

    return 0;
}
