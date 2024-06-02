#include <stdio.h>

void displayPolynomial(int coefficients[], int degree) {
      int i;

      for (i = degree; i >= 0; i--) {
            if (coefficients[i] != 0) {
                  if (i == degree) {
                        printf("%dx^%d", coefficients[i], i);
                  } else if (i == 1) {
                        printf(" + %dx", coefficients[i]);
                  } else {
                        printf(" + %dx^%d", coefficients[i], i);
                  }
            }
      }
      printf("\n");
}

int main() {
      int coefficients[] = {2, -3, 0, 5}; // Example coefficients
      int degree = sizeof(coefficients) / sizeof(coefficients[0]) - 1;

      displayPolynomial(coefficients, degree);

      return 0;
}