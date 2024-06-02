#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int *pointer = array;

    printf("Printing values using array indexing:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    printf("\nPrinting values using pointer arithmetic:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(pointer + i));
    }

    return 0;
}
