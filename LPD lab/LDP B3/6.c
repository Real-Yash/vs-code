#include <stdio.h>

void generateMagicSquare(int n) {
      int magicSquare[n][n];
      int i, j;

      // Initialize all elements of magic square to 0
      for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  magicSquare[i][j] = 0;
            }
      }

      // Set the starting position for 1
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

      // Display the magic square
      printf("Magic Square of size %d:\n", n);
      for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  printf("%d\t", magicSquare[i][j]);
            }
            printf("\n");
      }
}

int main() {
      int n;

      printf("Enter the size of the magic square (odd number): ");
      scanf("%d", &n);

      // Ensure the entered number is odd
      while (n % 2 == 0) {
            printf("Magic squares are only defined for odd-sized grids.\n Please enter an odd number: ");
            scanf("%d", &n);
      }

      generateMagicSquare(n);

      return 0;
}
