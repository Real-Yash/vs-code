#include <stdio.h>

int main() {
    float length, width, area;

    // Get the length and width of the rectangle from the user
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    // Calculate the area of the rectangle
    area = length * width;

    // Display the area
    printf("The area of the rectangle is: %.2f\n", area);

    return 0;
}
