#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float marks;

public:
    // Default constructor
    Student() {
        cout << "This is default constructor" << endl;
    }

    // Parameterized constructor
    Student(string n, int r, float m) : name(n), roll(r), marks(m) {
        cout << "This is parameterized constructor" << endl;
    }

    // Copy constructor
    Student(const Student& s) : name(s.name), roll(s.roll), marks(s.marks) {
        cout << "This is copy constructor" << endl;
    }

    // Getter methods
    string getName() const { return name; }
    int getRoll() const { return roll; }
    float getMarks() const { return marks; }

    // Setter methods
    void setName(string n) { name = n; }
    void setRoll(int r) { roll = r; }
    void setMarks(float m) { marks = m; }
};

int main() {
    // Default constructor
    Student s1;

    // Parameterized constructor
    Student s2("Yash", 77, 90);
    cout << "Student Name: " << s2.getName() << ", Roll No: " << s2.getRoll() << ", Marks: " << s2.getMarks() << endl;

    // Copy constructor
    Student s3(s2);
    cout << "Student Name: " << s3.getName() << ", Roll No: " << s3.getRoll() << ", Marks: " << s3.getMarks() << endl;

    return 0;
}
