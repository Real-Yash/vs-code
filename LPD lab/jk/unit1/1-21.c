#include <stdio.h>

// Structure to represent a term in the polynomial
typedef struct {
      int coefficient;
      int exponent;
} Term;

// Function to subtract two polynomials
void subtractPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
      int i = 0, j = 0;

      while (i < size1 && j < size2) {
            if (poly1[i].exponent > poly2[j].exponent) {
                  printf("%dx^%d ", poly1[i].coefficient, poly1[i].exponent);
                  i++;
            } else if (poly1[i].exponent < poly2[j].exponent) {
                  printf("%dx^%d ", -poly2[j].coefficient, poly2[j].exponent);
                  j++;
            } else {
                  int coefficient = poly1[i].coefficient - poly2[j].coefficient;
                  int exponent = poly1[i].exponent;
                  if (coefficient != 0) {
                        printf("%dx^%d ", coefficient, exponent);
                  }
                  i++;
                  j++;
            }
      }

      // Print remaining terms of poly1, if any
      while (i < size1) {
            printf("%dx^%d ", poly1[i].coefficient, poly1[i].exponent);
            i++;
      }

      // Print remaining terms of poly2, if any
      while (j < size2) {
            printf("%dx^%d ", -poly2[j].coefficient, poly2[j].exponent);
            j++;
      }
}

int main() {
      // Example usage
      Term poly1[] = {{3, 4}, {2, 3}, {5, 2}, {1, 0}};
      int size1 = sizeof(poly1) / sizeof(poly1[0]);

      Term poly2[] = {{2, 3}, {4, 2}, {1, 1}, {3, 0}};
      int size2 = sizeof(poly2) / sizeof(poly2[0]);

      printf("Subtraction of two polynomials: ");
      subtractPolynomials(poly1, size1, poly2, size2);

      return 0;
}