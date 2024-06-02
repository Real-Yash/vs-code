#include <stdio.h>

int main() {
      int arr[5] = {1, 2, 3, 4, 5};
      int *ptr = arr; // Assign the pointer to the start of the array

      // Print the array using pointer arithmetic
      for (int i = 0; i < 5; i++) {
            printf("%d ", *(ptr + i)); // Access array elements using pointer arithmetic
      }

      return 0;
}