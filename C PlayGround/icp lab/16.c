#include <stdio.h>

int main() {
    int values[5], i, sum = 0;
    float average;

    printf("Enter 5 integers: ");

    // taking input and storing it in an array
    for(i = 0; i < 5; ++i) {
       scanf("%d", &values[i]);
       sum += values[i];
    }

    // calculate average
    average = sum / 5.0;

    printf("Sum of the integers: %d\n", sum);
    printf("Average of the integers: %.2f\n", average);

    return 0;
}
