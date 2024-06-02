#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int age;

    // Constructor to initialize the object
    Student(string n, int r, int a) {
        name = n;
        roll = r;
        age = a;
    }

    // Method to display the details
    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Student Roll No: " << roll << endl;
        cout << "Student Age: " << age << endl;
    }
};

int main() {
    string name;
    int roll;
    int age;

    // Read the details
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the roll number of the student: ";
    cin >> roll;
    cout << "Enter the age of the student: ";
    cin >> age;

    // Create the student object
    Student s(name, roll, age);

    // Display the details
    s.display();

    return 0;
}
