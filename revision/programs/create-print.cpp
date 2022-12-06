#include <iostream>    // create-print.cpp
using namespace std;

struct A{
  int i;
  A(int a = 3): i{a}{ }
  ~A(){ cout << "Destroy: " << i << endl; }
};

void print( const A &  a ){ cout << "const A&: " << a.i << endl; }
void print( A & a ){ cout << "A&: " << a.i << endl; }
void print( A && a ){ cout << "A&&: " << a.i << endl; }

A bar(){ A a; return a; }

int main(){
  cout << "1. "; 
  print( bar() );  //temp A(3); destroyed after statement

  cout << "\n2. ";  const int & ci = 7;
  print( ci ) ;   // temp A(7); destroyed after statement

  cout << "\n3. ";  const A & cA = 11;
  print( cA ) ;   // temp A(11); persists till end of scope 

  cout << "\n4. "; 
  A && ir = bar();  // ir becomes an lvalue!  temp A(3)
  ir = 19;  // temp A(19) and subsequently copied to ir. Destroy A(19)
  print( ir ) ;  // lvalue printing

  cout << endl;  return 1; }
