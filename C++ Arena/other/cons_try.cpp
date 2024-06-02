#include <iostream>
#include <string>
using namespace std;

class student {
private:
    char name;
    double fee;
    int roll_no;

public:
    
    student(string n, double f, int r) : name(n), fee(f), roll_no(r) {}

    void Read() {
        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter Your fee : ";
        cin >> fee;

        cout << "Enter your roll no: ";
        cin >> roll_no;
    }
};
