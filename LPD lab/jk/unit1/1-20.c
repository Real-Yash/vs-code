#include <stdio.h>

// Structure to represent a term in the polynomial
typedef struct {
      int coefficient;
      int exponent;
} Term;

// Function to add two polynomials
void addPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
      int i = 0, j = 0;

      while (i < size1 && j < size2) {
            if (poly1[i].exponent > poly2[j].exponent) {
                  printf("%dx^%d ", poly1[i].coefficient, poly1[i].exponent);
                  i++;
            } else if (poly1[i].exponent < poly2[j].exponent) {
                  printf("%dx^%d ", poly2[j].coefficient, poly2[j].exponent);
                  j++;
            } else {
                  int sum = poly1[i].coefficient + poly2[j].coefficient;
                  if (sum != 0) {
                        printf("%dx^%d ", sum, poly1[i].exponent);
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
            printf("%dx^%d ", poly2[j].coefficient, poly2[j].exponent);
            j++;
      }
}

int main() {
      // Example polynomials
      Term poly1[] = {{5, 4}, {3, 2}, {2, 1}};
      Term poly2[] = {{-2, 4}, {4, 3}, {1, 2}, {6, 0}};

      int size1 = sizeof(poly1) / sizeof(poly1[0]);
      int size2 = sizeof(poly2) / sizeof(poly2[0]);

      printf("Polynomial 1: ");
      for (int i = 0; i < size1; i++) {
            printf("%dx^%d ", poly1[i].coefficient, poly1[i].exponent);
      }

      printf("\nPolynomial 2: ");
      for (int i = 0; i < size2; i++) {
            printf("%dx^%d ", poly2[i].coefficient, poly2[i].exponent);
      }

      printf("\n\nAddition of polynomials: ");
      addPolynomials(poly1, size1, poly2, size2);

      return 0;
}