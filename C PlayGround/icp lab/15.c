#include <stdio.h>

int main() {
    int values[5], i;

    printf("Enter 5 integers: ");

    // taking input and storing it in an array
    for(i = 0; i < 5; ++i) {
       scanf("%d", &values[i]);
    }

    printf("Displaying integers: ");

    // printing elements of an array
    for(i = 0; i < 5; ++i) {
       printf("%d\n", values[i]);
    }

    return 0;
}
