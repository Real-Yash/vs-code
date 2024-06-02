#include <iostream>
using namespace std;

// Single Level Inheritance

// class main1 {
//     public:
//     void display() {
//     cout << "**Single Level Inheritance**" <<endl;
// }
// };

class Base1 {
public:
    void func1() {
        cout <<"\n\n******Single Level Inheritance******" <<endl;
        // cout << "this is base1 fucction1" <<endl;
        cout << "Base1::func1()" << endl;
    }
};

class Derived1 : public Base1 {
public:
    void func2() {
        // cout << " this is derived function 2 for single  level inheritance."<<endl;
        cout << "Derived1::func2()" << endl;
    }
};

// Multilevel Inheritance

// class main2 {
//     public:
//     void display() {
//     cout << "**multi Level Inheritance**" <<endl;
// }
// };

class Base2 {
public:
    void func1() {
        cout << "\n\n*******multi Level Inheritance******" <<endl;
        cout << "Base2::func1()" << endl;
    }
};

class Derived2 : public Base2 {
public:
    void func2() {
        cout << "Derived2::func2()" << endl;
    }
};

class MultiDerived : public Derived2 {
public:
    void func3() {
        cout << "MultiDerived::func3()" << endl;
    }
};

// Hierarchical Inheritance
// class main1 {
//     public:
//     void display() {
//     cout << "**hierarchical Inheritance**" <<endl;
// }
// };

class Base3 {
public:
    void func1() {
        cout << "\n\n*******hierarchical Inheritance******" <<endl;
        cout << "Base3::func1()" << endl;
    }
};

class Derived31 : public Base3 {
public:
    void func2() {
        cout << "Derived31::func2()" << endl;
    }
};

class Derived32 : public Base3 {
public:
    void func3() {
        cout << "Derived32::func3()" << endl;
    }
};

// Multiple Inheritance
// class main1 {
//     public:
//     void display() {
//     cout << "**Multiple Inheritance**" <<endl;
// }
// };
class Base4 {
public:
    void func1() {
        cout << "\n \n*******Multiple Inheritance*******" <<endl;
        cout << "Base4::func1()" << endl;
    }
};

class Base5 {
public:
    void func2() {
        cout << "Base5::func2()" << endl;
    }
};

class MultiInherited : public Base4, public Base5 {
public:
    void func3() {
        cout << "MultiInherited::func3() \n \n " << endl;
    }
};

int main() {
    Derived1 d1;
    d1.func1();
    d1.func2();

    MultiDerived m;
    m.func1();
    m.func2();
    m.func3();

    Derived31 d31;
    d31.func1();
    d31.func2();

    Derived32 d32;
    d32.func1();
    d32.func3();

    MultiInherited mi;
    mi.func1();
    mi.func2();
    mi.func3();

    return 0;
}