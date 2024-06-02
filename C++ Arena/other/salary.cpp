#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int number;
    double HRA;
    float DA, salary, netSalary;
    float tax;

public:
    void Read() {
        cout << "Enter employee name: ";
        cin >> name;

        cout << "Enter employee number: ";
        cin >> number;

        cout << "Enter employee salary: ";
        cin >> salary;

        cout << "Enter employee HRA: ";
        cin >> HRA;

        cout << "Enter total salary: ";
        cin >> netSalary;
    }
};

int main() {
    Employee emp;
    emp.Read();


    return 0;
}
