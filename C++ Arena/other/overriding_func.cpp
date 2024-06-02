#include <iostream>
using namespace std;

class parent{
public:
    parent(){
        cout << "this is parent class \n";
    }
    
    virtual void print(){
        cout << "this is parent class function \n";
    }
};

class child : public parent{
public:
    child(){
        cout << "this is child class \n";
    }
    
    void print() override{
        cout << "this is child class function \n";
    }
};

int main(){
    parent p;
    child c;
    
    p.print(); // this will call the parent class function
    c.print(); // this will call the child class function
    
    return 0;
}