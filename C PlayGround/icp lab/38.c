#include <stdio.h>

void print_array(int* array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    print_array(array, 5);
    return 0;
}
