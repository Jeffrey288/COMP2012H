// C++ program to demonstrate how default arguments
// and virtual function are used together
#include <iostream>   // default-value.cpp
using namespace std;
 
class Base {
public:
  virtual void fun(int x = 0, int y = 7) {
    cout << "Base::fun(), x = " << x << "; y = " << y << endl;
  }
};
 
class Derived : public Base {
public:
  virtual void fun(int x = 10, int y = 31) {
      cout << "Derived::fun(), x = " << x << "; y = " << y << endl;
  }
};

int main() {
  Derived d;  Base* bp = &d;
  d.fun();       // Derived::fun(), x = 10; y = 31
  bp->fun();     // Derived::fun(), x = 0; y = 7
  bp->fun(3);    // Derived::fun(), x = 3; y = 7
  bp->fun(4, 5); // Derived::fun(), x = 4; y = 5
  return 0; }
