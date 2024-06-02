#include <iostream>
using namespace std;

class grandparent{
      public:
      void func1(){
            cout << "this is Function 1 from Parent"<< endl;
      }
};

class parent : public grandparent{
      public:
      void func2(){
            cout << "this is function  2 from Child" << endl;
      }
};

class child : public parent{
      public:
      void func3(){
            cout << "this is function 3 form child2" << endl;
      }
};

int main(){
      child c;
      c.func1();
      c.func2();
      c.func3();

      return 0;
}