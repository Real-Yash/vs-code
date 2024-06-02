#include <stdio.h>

int main() {
    int n, i, j, isPrime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Prime numbers from 1 to %d are: ", n);

    for(i = 2; i <= n; i++) {
        isPrime = 1; // assume number is prime
        for(j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                isPrime = 0; // number is not prime
                break;
            }
        }
        // if number is prime then print
        if(isPrime == 1)
            printf("%d ", i);
    }

    return 0;
}
