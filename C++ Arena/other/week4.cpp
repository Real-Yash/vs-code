#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "calling Default Constructor." << endl;
    }

    MyClass(int roll , string name) {
        cout << "Parameterized Constructor called with values " << roll << " and " << name << endl;
    }

    MyClass(const MyClass& obj) {
        cout << "Copy Constructor called." << endl;
    }
};

int main() {
    MyClass obj1; // Default Constructor
    MyClass obj2( 77 , "yash" ); // Parameterized Constructor
    MyClass obj3 = obj1; // Copy Constructor

    return 0;
}