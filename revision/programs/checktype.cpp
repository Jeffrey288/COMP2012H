/**
 * 26/10/2022
 * These are the programs I shared with you today on finding the class type
of a polymorphic object and calling its specialized functions
 */

#include <iostream>  // checktype.cpp
#include <typeinfo>
using namespace std;

// deterimination of class type is only for polymorphic base objects
struct B{ virtual void Bprint() const { cout << "Base B\n";} };
struct D1: public B{ void D1print() const { cout << "Derived1 D1\n"; } };
struct D2: public B{ void D2print() const { cout << "Derived2 D2\n"; } };

void print( const B & b ){
  if( typeid( b ) == typeid( class B )){
    b.Bprint(); return;
  }
  if( const D1 * d1p = dynamic_cast<const D1 *>( &b ) ){
    //    cout << b.D1print();  // error because struct b has no D1print()
    d1p -> D1print(); return;
  }
  if( typeid( b ).name() == typeid( D2 ).name() ){
    const D2 * d2p = static_cast<const D2 *>( &b );
    d2p -> D2print(); return;
  }
}

int main(){
  B * bp = new B;
  D1 d1;
  D2 d2, & d2r = d2;

  print( *bp ); print( d1 ); print( d2r );
  return 1;  }

/**
 * Output:
Base B
Derived1 D1
Derived2 D2
*/