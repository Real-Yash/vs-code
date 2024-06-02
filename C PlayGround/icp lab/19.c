#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Odd numbers from 1 to %d are: ", n);

    for(i = 1; i <= n; i++) {
        // if the number is not divisible by 2 then it is odd
        if(i % 2 != 0)
            printf("%d ", i);
    }

    return 0;
}
