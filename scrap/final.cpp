#include <iostream>
using namespace std;

class A { 
public:
  virtual void print() { cout << "a"; } 
};
class B : public A { 
public:
  virtual void print() final override { cout << "b"; } 
};
class C : public B {
public:
  void print() { cout << "c"; } // cannot, regardless of whether there is final, override or both or neither
};
int main() {
  std::cout << "Hello World!\n";
}