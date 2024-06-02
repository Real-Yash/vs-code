#include <iostream>
using namespace std;

class parent{
      public:
      void func1(){
            cout<<"this is function1 form parent function." << endl;
      }
};

class child : public parent {
      public: 
      void func2() {
            cout << "This is Function2 from Child class." << endl;
      }
};

int main(){
      child c;
      c.func1();
      c.func2();
      return 0;   
}