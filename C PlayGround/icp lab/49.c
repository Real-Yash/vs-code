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
    // Create an employee
    struct Employee employee;

    // Get the details of the employee from the user
    printf("Enter employee name: ");
    scanf("%s", employee.name);

    printf("Enter employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);

    // Display the employee details
    displayEmployee(employee);

    return 0;
}
