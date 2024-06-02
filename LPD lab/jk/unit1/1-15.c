#include <stdio.h>

// Function to display the polynomial
void displayPolynomial(int coefficients[], int degree) {
      for (int i = degree; i >= 0; i--) {
            if (coefficients[i] != 0) {
                  printf("%dx^%d ", coefficients[i], i);
                  if (i != 0) {
                        printf("+ ");
                  }
            }
      }
      printf("\n");
}

int main() {
      // Example polynomial: 3x^4 + 2x^3 - 5x^2 + 7x - 9
      int coefficients[] = {3, 2, -5, 7, -9};
      int degree = sizeof(coefficients) / sizeof(coefficients[0]) - 1;

      // Display the polynomial
      displayPolynomial(coefficients, degree);

      return 0;
}