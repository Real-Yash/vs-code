#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int rollNo;
    char grade;

    // Constructor to initialize the object
    Student() {
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter Roll Number:";
        std::cin >> rollNo;
        std::cout << "Enter Grade:";
        std::cin >> grade;
        std::cout << "\n";
    }

    // Method to display the details
    void displayDetails() {
        std::cout << "Name: " << name << ", Roll Number: " << rollNo << ", Grade: " << grade << std::endl;
    }
};

int main() {
    const int numOfStudents = 3;
    Student students[numOfStudents]; // Array of Student objects

    // Display details for each student
    std::cout << "\nStudent Details:\n";
    for (int i = 0; i < numOfStudents; ++i) {
        std::cout << "\nDetails for Student " << i + 1 << ":\n";
        students[i].displayDetails();
    }

    return 0;
}
