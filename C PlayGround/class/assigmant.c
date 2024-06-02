#include <stdio.h>

int main() {
    int a[100], n, i, x, power;
    float polySum;


    printf("Enter the order of polynomial: ");
    scanf("%d", &n);


    printf("Enter the value of x: ");
    scanf("%d", &x);


    printf("Enter the coefficients:\n");
    for (i = 0; i <= n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    polySum = a[0];

    for (i = 1; i <= n; i++) {
        polySum = polySum * x + a[i];
    }

  
    printf("Polynomial: ");
    power = n;
    for (i = 0; i <= n; i++) {
        if (a[i] != 0) {
            printf("%+.2fx^%d", a[i], power);
        }
        power--;
    }

  
    printf("\nPolynomial Sum = %.2f\n", polySum);

    return 0;
}
