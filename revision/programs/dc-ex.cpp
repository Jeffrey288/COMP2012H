/** 21/10/2022
 * As covered in course, a base class pointer may point to any of its
derived class objects down in the hierarchy including the base class. 
In the lecture today, I have shown you programs on how to discover the
object class a base pointer points to using dynamic_cast and typeid. 
Once you know the object class, you can then set the right derived class
pointer to the object to execute all its member functions, including the
non-virtual ones.
*/

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
  return 0; }
