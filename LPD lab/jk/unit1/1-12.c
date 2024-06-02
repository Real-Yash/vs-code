#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int** ptr) {
      *ptr = (int*)malloc(sizeof(int));
      if (*ptr == NULL) {
            printf("Memory allocation failed!");
            exit(1);
      }
}

int main() {
      int* ptr = NULL;
      allocateMemory(&ptr);

      // Access and modify the allocated memory
      *ptr = 42;
      printf("Value stored in the allocated memory: %d\n", *ptr);

      // Free the allocated memory
      free(ptr);

      return 0;
}