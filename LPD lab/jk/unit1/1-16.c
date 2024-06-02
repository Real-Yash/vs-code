#include <stdio.h>

// Function to add two single variable polynomials
void addPolynomials(int poly1[], int poly2[], int size1, int size2) {
      int maxSize = (size1 > size2) ? size1 : size2;
      int sum[maxSize];

      // Adding coefficients of polynomials
      for (int i = 0; i < maxSize; i++) {
            int term1 = (i < size1) ? poly1[i] : 0;
            int term2 = (i < size2) ? poly2[i] : 0;
            sum[i] = term1 + term2;
      }

      // Printing the sum polynomial
      printf("Sum of polynomials: ");
      for (int i = 0; i < maxSize; i++) {
            printf("%d ", sum[i]);
      }
      printf("\n");
}

int main() {
      int poly1[] = {2, 0, 3}; // First polynomial: 2x^2 + 3
      int size1 = sizeof(poly1) / sizeof(poly1[0]);

      int poly2[] = {1, 2, 1}; // Second polynomial: x^2 + 2x + 1
      int size2 = sizeof(poly2) / sizeof(poly2[0]);

      addPolynomials(poly1, poly2, size1, size2);

      return 0;
}