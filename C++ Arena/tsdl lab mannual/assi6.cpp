#include<iostream>
using namespace std;

class Employ {
public:
    int no;
    string name;
    float basic, hra, da, salary, bs, t, ns;

    // Constructor to initialize the object
    Employ(string n, int num, float s, float h, float d) {
        name = n;
        no = num;
        salary = s;
        hra = h;
        da = d;
    }

    // Method to calculate the basic salary and net salary
    void calculate() {
        bs = salary - (hra + da);
        t = 0.02 * bs;
        ns = salary - t;
    }

    // Method to display the details
    void display() {
        cout << "Basic salary of the employee is: " << bs << endl;
        cout << "Net salary of the employee is: " << ns << endl;
    }
};

int main() {
    string name;
    int no;
    float salary, hra, da;

    // Read the details
    cout << "Enter the name of the employee: ";
    cin >> name;
    cout << "Enter the employee number: ";
    cin >> no;
    cout << "Enter the employee's total salary: ";
    cin >> salary;
    cout << "Enter the employee's HRA: ";
    cin >> hra;
    cout << "Enter the employee's DA: ";
    cin >> da;

    // Create the Employ object
    Employ e(name, no, salary, hra, da);

    // Calculate and display the details
    e.calculate();
    e.display();

    return 0;
}
