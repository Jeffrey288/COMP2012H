/**
 * 26/10/2022
 * These are the programs I shared with you today on finding the class type
of a polymorphic object and calling its specialized functions
 */

#include <iostream>  // checktype2.cpp
#include <typeinfo>
using namespace std;
enum class_type {BASE, DERIVED1, DERIVED2};

struct B{ void Bprint() const { cout << "Base B\n";}
  virtual class_type type() const {return BASE;} };
struct D1: public B{ void D1print() const { cout << "Derived1 D1\n"; } 
  class_type type() const override {return DERIVED1;} };
struct D2: public B{ void D2print() const { cout << "Derived2 D2\n"; }
  virtual class_type type() const override {return DERIVED2;} };

void print( const B & b ){
  switch( b.type() ){
  case BASE: b.Bprint(); break;
  case DERIVED1: {
    const D1 * d1p = dynamic_cast<const D1 *>( &b );
    d1p -> D1print(); break;  }
  case DERIVED2:{
    const D2 * d2p = static_cast<const D2 *>( &b );
    d2p -> D2print(); break;  }
  default:
    cout << "No match\n"; break;  }
}

int main(){
  B * bp = new B;
  D1 d1;
  D2 d2, & d2r = d2;
  print( *bp ); print( d1 ); print( d2r );
  return 1; }
