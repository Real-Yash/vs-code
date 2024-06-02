#include <stdio.h>

// Function to perform scalar multiplication of a multivariable polynomial
void scalarMultiply(int poly[], int n, int scalar) {
      int i;

      // Multiply each coefficient of the polynomial by the scalar
      for (i = 0; i <= n; i++) {
            poly[i] = poly[i] * scalar;
      }
}

// Function to display the polynomial
void displayPolynomial(int poly[], int n) {
      int i;

      // Display the polynomial
      for (i = 0; i <= n; i++) {
            printf("%dx^%d ", poly[i], i);
            if (i != n) {
                  printf("+ ");
            }
      }
      printf("\n");
}

int main() {
      int poly[] = {2, -3, 1}; // Example polynomial: 2x^2 - 3x + 1
      int n = sizeof(poly) / sizeof(poly[0]);
      int scalar = 5; // Scalar value

      printf("Original Polynomial: ");
      displayPolynomial(poly, n - 1);

      scalarMultiply(poly, n - 1, scalar);

      printf("Scalar Multiplied Polynomial: ");
      displayPolynomial(poly, n - 1);

      return 0;
}