#include <stdio.h>

void generateMagicSquare(int n) {
      int magicSquare[n][n];
      int i, j;

      // Initialize all elements to 0
      for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  magicSquare[i][j] = 0;
            }
      }

      // Set the starting position
      int row = n / 2;
      int col = n - 1;

      // Fill the magic square
      for (int num = 1; num <= n * n; ) {
            if (row == -1 && col == n) {
                  col = n - 2;
                  row = 0;
            }
            else {
                  if (col == n) {
                        col = 0;
                  }
                  if (row < 0) {
                        row = n - 1;
                  }
            }

            if (magicSquare[row][col]) {
                  col -= 2;
                  row++;
                  continue;
            }
            else {
                  magicSquare[row][col] = num++;
            }

            col++;
            row--;
      }

      // Print the magic square
      printf("Magic Square of order %d:\n", n);
      for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  printf("%d\t", magicSquare[i][j]);
            }
            printf("\n");
      }
}

int main() {
      int order;

      printf("Enter the order of the magic square (odd number): ");
      scanf("%d", &order);

      generateMagicSquare(order);

      return 0;
}