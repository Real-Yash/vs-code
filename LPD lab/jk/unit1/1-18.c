#include <stdio.h>

// Function to multiply two polynomials
void multiplyPolynomials(int poly1[], int poly2[], int m, int n)
{
      // Create a result polynomial of size m+n-1
      int result[m + n - 1];
      int i, j;

      // Initialize the result polynomial
      for (i = 0; i < m + n - 1; i++)
            result[i] = 0;

      // Multiply each term of poly1 with poly2
      for (i = 0; i < m; i++)
      {
            for (j = 0; j < n; j++)
            {
                  result[i + j] += poly1[i] * poly2[j];
            }
      }

      // Print the result polynomial
      printf("Resultant polynomial: ");
      for (i = 0; i < m + n - 1; i++)
      {
            printf("%d ", result[i]);
      }
}

int main()
{
      // Example polynomials
      int poly1[] = {1, 2, 3}; // 1 + 2x + 3x^2
      int m = sizeof(poly1) / sizeof(poly1[0]);

      int poly2[] = {4, 5}; // 4 + 5x
      int n = sizeof(poly2) / sizeof(poly2[0]);

      // Multiply the polynomials
      multiplyPolynomials(poly1, poly2, m, n);

      return 0;
}