#include <stdio.h>
#include <stdlib.h>
int main() {

      int n;
      int* numbers;

      printf("Enter the number of elements: ");
      scanf("%d", &n);

      // Dynamically allocate memory for the numbers array
      numbers = (int*)calloc(4, sizeof(int));


      if (numbers == NULL) {
            printf("Memory allocation failed!");
            return 1;
      }


      printf("Enter %d numbers:\n", n);
      for (int i = 0; i < 2; i++) {
            scanf("%d", &numbers[i]);
      }


      printf("Numbers entered by the user:\n");
      for (int i = 0; i < 4; i++) {
            printf("%d ", numbers[i]);
      }


      // Free the dynamically allocated memory
      free(numbers);
      return 0;
}