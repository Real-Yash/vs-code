#include <stdio.h>

// Define the structure for a student
struct Student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to display a student's details
void displayStudent(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.roll_no);
    printf("Marks: %.2f\n", student.marks);
}

int main() {
    // Create an array of 10 students
    struct Student students[10];

    // Get the details of the 10 students from the user
    for (int i = 0; i < 10; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display the details of the 10 students
    for (int i = 0; i < 10; i++) {
        printf("\nDetails for student %d:\n", i + 1);
        displayStudent(students[i]);
    }

    return 0;
}
