#include <iostream>
using namespace std;

class parent{
      public:
      void func1(){
            cout << "this is function 1 form parent" << endl;
      }
};

class child1 : public parent {
      public:
      void func2() {
            cout << "this is function 2 form child1" << endl;
      }
};

class child2 : public parent{
      public:
      void func3(){
            cout  << "This is Function 3 from Child2"<<endl;
      }
};

int main(){

child1 c1;
c1.func1();
c1.func2();

child2 c2;
c2.func1();
c2.func3();

return 0;
}