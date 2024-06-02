#include <iostream>
#include <string>
using namespace std;

class student {
private:
    char name;
    double fee;
    int roll_no;

public:
    void Read() {
        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter Your fee : ";
        cin >> fee;

        cout << "Enter your roll no: ";
        cin >> roll_no;

    }
};