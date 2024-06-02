#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Even numbers from 1 to %d are: ", n);

    for(i = 2; i <= n; i++) {
        // if the number is divisible by 2 then it is even
        if(i % 2 == 0)
            printf("%d ", i);
    }

    return 0;
}
