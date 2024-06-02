#include <stdio.h>

int main() {
    int marks;

    // Get the marks from the user
    printf("Enter the marks: ");
    scanf("%d", &marks);

    // Calculate the grade based on the marks
    if (marks >= 85) {
        printf("Grade: A\n");
    } else if (marks >= 70) {
        printf("Grade: B\n");
    } else if (marks >= 55) {
        printf("Grade: C\n");
    } else if (marks >= 40) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}
