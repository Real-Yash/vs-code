#include <stdio.h>

// Define the structure for an employee
struct Employee {
    char name[50];
    int id;
    float salary;
};

// Function to display an employee's details
void displayEmployee(struct Employee employee) {
    printf("Name: %s\n", employee.name);
    printf("ID: %d\n", employee.id);
    printf("Salary: %.2f\n", employee.salary);
}

int main() {
    // Create an array of 10 employees
    struct Employee employees[10];

    // Get the details of the 10 employees from the user
    for (int i = 0; i < 10; i++) {
        printf("Enter details for employee %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", employees[i].name);

        printf("Enter ID: ");
        scanf("%d", &employees[i].id);

        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Display the details of the 10 employees
    for (int i = 0; i < 10; i++) {
        printf("\nDetails for employee %d:\n", i + 1);
        displayEmployee(employees[i]);
    }

    return 0;
}
