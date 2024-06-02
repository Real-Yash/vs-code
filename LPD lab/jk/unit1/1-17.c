#include <stdio.h>

// Function to subtract two polynomials
void subtractPolynomials(int poly1[], int poly2[], int size1, int size2) {
      int resultSize = (size1 > size2) ? size1 : size2;
      int result[resultSize];

      // Subtract corresponding coefficients
      for (int i = 0; i < resultSize; i++) {
            int coeff1 = (i < size1) ? poly1[i] : 0;
            int coeff2 = (i < size2) ? poly2[i] : 0;
            result[i] = coeff1 - coeff2;
      }

      // Print the result polynomial
      printf("Result: ");
      for (int i = resultSize - 1; i >= 0; i--) {
            printf("%dx^%d ", result[i], i);
            if (i > 0) {
                  printf("+ ");
            }
      }
      printf("\n");
}

int main() {
      // Example polynomials
      int poly1[] = {3, 2, 1};  // 3x^2 + 2x + 1
      int size1 = sizeof(poly1) / sizeof(poly1[0]);

      int poly2[] = {1, 2, 3};  // x^2 + 2x + 3
      int size2 = sizeof(poly2) / sizeof(poly2[0]);

      // Subtract the polynomials
      subtractPolynomials(poly1, poly2, size1, size2);

      return 0;
}