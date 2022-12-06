#include<iostream>     // inh-construct.cpp
using namespace std;

struct A{
  A(){ cout << "A's default constructor\n"; }
  A(const A &a){ cout << "A's copy constructor\n"; }
  A(int a){ cout << "A's conversion constructor\n"; }
};

struct B: public A{
  B(){ cout << "B's default constructor\n"; }  // same as B(): A() {...}
  B(const B& b){ cout << "B's copy constructor\n"; }  
  B(const A& a){ cout << "B's conversion constructor\n"; } 
};

int main(){
  B b(10);   // matches to const A & a = A{10} or const A & a = A(10)
  return 0;
}

/* Output:
A's conversion constructor
A's default constructor
B's conversion constructor
*/

