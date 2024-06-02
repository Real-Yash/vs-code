#include <stdio.h>
#include <stdlib.h>

int main() {
      int* numbers = NULL;
      int size = 5;

      // Dynamically allocate memory for the initial array
      numbers = (int*)realloc(numbers, size * sizeof(int));

      // Read numbers from the user
      printf("Enter %d numbers:\n", size);
      for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
      }

      // Display the numbers given by the user
      printf("Numbers given by the user:\n");
      for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
      }
      printf("\n");

      // Increase the size of the array by 5
      size += 5;
      numbers = (int*)realloc(numbers, size * sizeof(int));

      // Read the additional numbers from the user
      printf("Enter %d more numbers:\n", size - 5);
      for (int i = 5; i < size; i++) {
            scanf("%d", &numbers[i]);
      }

      // Display the updated series
      printf("Updated series:\n");
      for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
      }
      printf("\n");

      // Free the dynamically allocated memory
      free(numbers);

      return 0;
}