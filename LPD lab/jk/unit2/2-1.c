#include <stdio.h>

#define ROWS 3
#define COLS 3

void findSaddlePoint(int matrix[ROWS][COLS]) {
      int i, j, min, max, row, col;

      for (i = 0; i < ROWS; i++) {
            min = matrix[i][0];
            col = 0;

            // Find the minimum element in the current row
            for (j = 1; j < COLS; j++) {
                  if (matrix[i][j] < min) {
                        min = matrix[i][j];
                        col = j;
                  }
            }

            // Check if the minimum element is also the maximum in its column
            max = matrix[0][col];
            row = 0;

            for (j = 1; j < ROWS; j++) {
                  if (matrix[j][col] > max) {
                        max = matrix[j][col];
                        row = j;
                  }
            }

            // If the minimum element is also the maximum in its column, it is a saddle point
            if (min == max) {
                  printf("Saddle point found at (%d, %d): %d\n", row, col, min);
                  return;
            }
      }

      printf("No saddle point found.\n");
}

int main() {
      int matrix[ROWS][COLS] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
      };

      findSaddlePoint(matrix);

      return 0;
}