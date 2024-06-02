#include <stdio.h>

// Define the structure for a point
struct Point {
    float x;
    float y;
};

// Function to swap two points
void swapPoints(struct Point* p1, struct Point* p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    // Create two points
    struct Point point1, point2;

    // Get the coordinates of the first point from the user
    printf("Enter x and y coordinates for the first point: ");
    scanf("%f %f", &point1.x, &point1.y);

    // Get the coordinates of the second point from the user
    printf("Enter x and y coordinates for the second point: ");
    scanf("%f %f", &point2.x, &point2.y);

    // Swap the two points
    swapPoints(&point1, &point2);

    // Display the coordinates of the swapped points
    printf("After swapping:\n");
    printf("Coordinates of the first point: (%.2f, %.2f)\n", point1.x, point1.y);
    printf("Coordinates of the second point: (%.2f, %.2f)\n", point2.x, point2.y);

    return 0;
}
