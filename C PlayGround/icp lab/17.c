#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int values[n];

    printf("Enter %d integers: ", n);

    // taking input and storing it in an array
    for(i = 0; i < n; ++i) {
       scanf("%d", &values[i]);
    }

    printf("Cubes of the integers: ");

    // printing cubes of elements of an array
    for(i = 0; i < n; ++i) {
       printf("%d\n", values[i]*values[i]*values[i]);
    }

    return 0;
}
