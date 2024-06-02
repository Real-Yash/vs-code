#include <iostream>
using namespace std;

class parent {
public:
      void print() {
      cout<< "this is parent";
      }
};


class child: public parent {
public:
      void print() {
      cout<<"this is child ";
}
};

int main() {
child c;
c.print();
return 0;

}