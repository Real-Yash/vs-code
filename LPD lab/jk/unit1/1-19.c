#include <stdio.h>

void displayPolynomial(int coefficients[], int numVariables, int degree) {
      int i, j;
      int count = 0;

      for (i = 0; i <= degree; i++) {
            for (j = 0; j <= numVariables; j++) {
                  if (coefficients[count] != 0) {
                        printf("%dx^%d", coefficients[count], i);
                        if (j < numVariables) {
                              printf(" * ");
                        }
                  }
                  count++;
            }
      }
      printf("\n");
}

int main() {
      int coefficients[] = {1, 2, 3, 4, 5, 6}; // Example coefficients
      int numVariables = 2; // Number of variables in the polynomial
      int degree = 2; // Degree of the polynomial

      displayPolynomial(coefficients, numVariables, degree);

      return 0;
}