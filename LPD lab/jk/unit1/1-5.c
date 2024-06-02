#include <stdio.h>
#include <stdlib.h>

int main() {
      int numStudents = 5;
      int* scores = (int*)malloc(numStudents * sizeof(int));

      if (scores == NULL) {
            printf("Memory allocation failed!");
            return 1;
      }

      printf("Enter the scores of %d students:\n", numStudents);
      for (int i = 0; i < numStudents; i++) {
            printf("Student %d: ", i + 1);
            scanf("%d", &scores[i]);
      }

      int sum = 0;
      for (int i = 0; i < numStudents; i++) {
            sum += scores[i];
      }

      float average = (float)sum / numStudents;
      printf("Average score: %.2f\n", average);

      free(scores);

      return 0;
}