#include <stdio.h>

void generateMagicSquare(int n) {
      int magicSquare[n][n];
      int i, j, num;

      // Initialize all elements of magic square to 0
      for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  magicSquare[i][j] = 0;
            }
      }

      // Set the initial position of 1
      i = n / 2;
      j = n - 1;

      // Fill the magic square
      for (num = 1; num <= n * n; ) {
            if (i == -1 && j == n) {
                  i = 0;
                  j = n - 2;
            }
            else {
                  if (j == n) {
                        j = 0;
                  }
                  if (i < 0) {
                        i = n - 1;
                  }
            }

            if (magicSquare[i][j]) {
                  i++;
                  j -= 2;
                  continue;
            }
            else {
                  magicSquare[i][j] = num++;
            }

            i--;
            j++;
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

      printf("Enter the order of the magic square (should be even): ");
      scanf("%d", &order);

      if (order % 2 != 0) {
            printf("Invalid order! Please enter an even number.\n");
            return 0;
      }

      generateMagicSquare(order);

      return 0;
}