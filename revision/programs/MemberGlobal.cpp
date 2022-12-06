#include <iostream>  // MemberGlobal.cpp
using namespace std;
struct foo{
  void operator!() { // member ! for non-constant object
    cout << "non-constant member operator!\n"; }  
  // void operator!() const { /* error: clashes with the global ! */ }
  void operator+( const foo & f ) const; };

void foo::operator+( const foo & f ) const { // member + for const obj
  cout << "constant member operator+\n";  } 

void operator!( const foo& f ){  // global ! for constant foo object
  cout << "global operator! for constant object\n";  }

void operator+( foo& f, const foo& g ){ // global+ for non-const foo obj
  cout << "global operator+ for non-constant object\n";  }

int main(){
  foo f, g; const foo cf, cg;

  cout << "!f: "; !f;   // same as !(f) and the explicit f.operator!()
  cout << "operator!(f): "; operator!(f); // call explicitly global !
  cout << "!cf: "; !cf; cout << endl;  // implicit matching by compiler
  // cf.operator!(); // explicit call error: const obj calling non-const fnctn
  
  cout << "f+cg: "; f+cg;  // implicitly matches to global +.  Same as f+(cg)
  cout << "f.operator+(cg): "; f.operator+(cg);  // explicit call member +
  cout << "cf + g: "; cf + g;   // implictly matches to member +
  //  cout << "operator+(cf, g): "; operator+(cf, g);   // explicit call error
  return 1; }
