#include <iostream>     // typeid.cpp
#include <typeinfo>
using namespace std;

//using polymorphic base class B1
class B1 {
public: virtual void fun() {}  };

//using non-polymorphic base class B2
class B2 {};

class D1 : public B1 {};
class D2 : public B2 {};

int main() {
  D1* d1 = new D1;  B1* b1 = d1;     // b1 points to polymorphic D1 object
  D2* d2 = new D2;  B2* b2 = d2;     // b2 points to non-polymorphic D2 object
  //Printing the type of above class objects on the console
  cout << "1. " << typeid( d1 ).name() << endl;   // pointer to D1 type
  cout << "2. " << typeid( b1 ).name() << endl;   // pointer to B1 type
  cout << "3. " << typeid( *d1 ).name() << endl;  
  cout << "4. " << typeid( *b1 ).name() << endl;  // *b1 is D1 object
  cout << "5. " << typeid( d2 ).name() << endl;   
  cout << "6. " << typeid( b2 ).name() << endl;   // pointer to D2 object
  cout << "7. " << typeid( *d2 ).name() << endl;  
  cout << "8. " << typeid( *b2 ).name() << endl;  // *b2 is B2!

  if( typeid( *b1 ) == typeid( class D1 ) )
    cout << "*b1 is of class D1\n";
  if( typeid( *b2 ).name() == typeid( B2 ).name() )
    cout << "*b2 is of class B2\n";
  return 0; }
