#include <stdio.h>
#include <math.h>

// Define the structure for a point
struct Point {
    float x;
    float y;
};

// Function to calculate the distance between two points
float calculateDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
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

    // Calculate and display the distance between the two points
    printf("The distance between the two points is: %.2f\n", calculateDistance(point1, point2));

    return 0;
}
