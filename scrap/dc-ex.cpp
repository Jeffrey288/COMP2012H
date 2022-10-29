#include <iostream>   // dc-ex.cpp
#include <typeinfo>
using namespace std;

// dynamic_cast() is for polymorphic object: MUST have virtual function
class Base {  virtual void print(){}  };

class Derived1 : public Base { };
class Derived2 : public Base {  void print(){}  };

int main() {
  Derived1 d1;
  Base* bp = dynamic_cast<Base*>(&d1);  // same as Base* bp = &d1;
  
  // Check object type with dynamic_cast
  if( dynamic_cast<Derived1 *>(bp) )
    cout << "bp points to a Derived1 object\n";
  if( dynamic_cast<Derived2 *>(bp) == nullptr )
    cout << "bp does NOT point to a Derived2 object\n";
  
  Base & br = d1;  // check reference variable
  if( dynamic_cast<Derived1* >(&br) )
    cout << "br is a Derived1 object\n";

  // Derived1 & d1r = br; // compilation error
  Derived1 & d1r = dynamic_cast<Derived1 &>(br);  //ok. No exception thrown
  try{
    Derived2 & d2r = dynamic_cast<Derived2 &>(br); // throw bad_cast exception
  }
  catch(bad_cast){ cout << "bad cast\n"; } 
  return 0; 
}
