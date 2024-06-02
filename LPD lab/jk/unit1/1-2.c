#include <stdio.h>
#include <stdlib.h>

int main() {
      int n;
      printf("Enter the number of elements: ");
      scanf("%d", &n);

      // Allocate memory using calloc
      int* numbers = (int*)calloc(n, sizeof(int));

      if (numbers == NULL) {
            printf("Memory allocation failed!");
            return 1;
      }

      printf("Enter %d numbers:\n", n);
      for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
      }

      printf("Numbers entered by the user:\n");
      for (int i = 0; i < n; i++) {
            printf("%d ", numbers[i]);
      }

      // Free the allocated memory
      free(numbers);

      return 0;
}