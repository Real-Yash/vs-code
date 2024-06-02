#include <iostream>
using namespace std;

class dad{
      public:
      void func1(){
            cout << "Dad loves his son" << endl;
      }
};

class mom{
      public:
      void func2(){
            cout << "Mom loves her son" << endl;
      }
};

class child : public  dad, public mom {
       public:
       void func3(){
            cout << "Son loves mom and dad too " << endl;
       }
};

int main(){

      child c;
      c.func1();
      c.func2();
      c.func3();

      return 0;
}