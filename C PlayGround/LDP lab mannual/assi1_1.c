// Implementation of single dimensional array using dynamic memory allocation and perform accept and display function on it.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *Array;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Size should be a positive integer\n");
        return 1;
    }

    Array = (int*)calloc(size, sizeof(int));
    if (Array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &Array[i]);
    }


    printf("Elements in the array are\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    free(Array);

    return 0;
}
