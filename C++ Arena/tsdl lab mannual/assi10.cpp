#include <iostream>
using namespace std;

class Grandparent {
public:
    void func1() {
        cout << "This is Function 1 from Grandparent" << endl;
    }
};

class Parent : public Grandparent {
public:
    void func2() {
        cout << "This is function 2 from Parent" << endl;
    }
};

class Child1 : public Parent {
public:
    void func3() {
        cout << "This is function 3 from Child1" << endl;
    }
};

class Child2 : public Parent {
public:
    void func4() {
        cout << "This is function 4 from Child2" << endl;
    }
};

class Dad {
public:
    void func5() {
        cout << "Dad loves his son" << endl;
    }
};

class Mom {
public:
    void func6() {
        cout << "Mom loves her son" << endl;
    }
};

class Child3 : public Dad, public Mom {
public:
    void func7() {
        cout << "Son loves mom and dad too" << endl;
    }
};

int main() {
    Child1 c1;
    c1.func1();
    c1.func2();
    c1.func3();

    Child2 c2;
    c2.func1();
    c2.func2();
    c2.func4();

    Child3 c3;
    c3.func5();
    c3.func6();
    c3.func7();

    return 0;
}
