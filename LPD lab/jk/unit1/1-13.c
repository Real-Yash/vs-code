#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size) {
      for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
      }
      printf("\n");
}

int main() {
      int size;
      printf("Enter the size of the array: ");
      scanf("%d", &size);

      int* arr = (int*)malloc(size * sizeof(int));

      printf("Enter the elements of the array: ");
      for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
      }

      printf("Array elements: ");
      printArray(arr, size);

      free(arr);

      return 0;
}