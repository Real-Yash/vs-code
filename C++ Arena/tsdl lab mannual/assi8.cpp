#include<iostream>
using namespace std;

class Student {
public:
    int age;

    // Constructor to initialize the object
    Student() {
        cout << "Enter your age: ";
        cin >> age;
    }

    // Method to display the details
    void display() {
        cout << "His age is " << age << endl;
    }
};

int main() {
    // Create and display the details of the first student
    Student s1;
    s1.display();

    // Create and display the details of the second student
    Student* s2 = new Student;
    s2->display();

    // Don't forget to delete the dynamically allocated student
    delete s2;

    return 0;
}
