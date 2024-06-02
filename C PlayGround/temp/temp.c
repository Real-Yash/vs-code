#include <stdio.h>

int main() {
    int a[100], n, i, x, power;
    float polySum;

    // STEP 1: Import the header file

    // STEP 2: Define variables

    // STEP 3: Accept order of polynomial
    printf("Enter the order of polynomial: ");
    scanf("%d", &n);

    // STEP 4: Accept value of x
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // STEP 5: Accept coefficients
    printf("Enter the coefficients:\n");
    for (i = 0; i <= n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // STEP 6: Initialize polySum
    polySum = a[0];

    // STEP 7: Calculate polySum
    for (i = 1; i <= n; i++) {
        polySum = polySum * x + a[i];
    }

    // STEP 8: Print polynomial
    printf("Polynomial: ");
    power = n;
    for (i = 0; i <= n; i++) {
        if (a[i] != 0) {
            printf("%+.2fx^%d", a[i], power);
        }
        power--;
    }

    // STEP 11: Print polySum
    printf("\nPolynomial Sum = %.2f\n", polySum);

    return 0;
}
