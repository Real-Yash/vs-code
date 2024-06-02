#include <stdio.h>

int main() {
    int num1, num2, i, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    for(i=1; i <= num1 && i <= num2; ++i) {
        // Checks if i is factor of both integers
        if(num1%i==0 && num2%i==0)
            gcd = i;
    }

    printf("GCD of %d and %d is %d", num1, num2, gcd);

    return 0;
}
