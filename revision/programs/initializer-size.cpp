/**
 * 19/10/2022
 * I covered order of construction of MIL (member initializer list) today. 
 */

#include <iostream>  // initializer-size.cpp
using namespace std;

class A{
public: A( int i = 0 ){cout << "A(" << i << ") created\n";}
};

struct B{
  B(){cout << "B created\n";}
};  // B b;

struct C{
  const int & j = i;  const int i = 7; 
};

class foo{
private:
  A a;  B b;  A a2;
  const int & j;  
  const int i; // this should have been put before a2 statement

public:
  foo(): i{7}, b(), j{i}, a2{i}, a() { cout << "j is " << j << endl;}
};

int main(){
  foo f;  // check the order of data member construction
  // check size of class and struct
  cout << "\nSize of C = " << sizeof(struct C)<< endl;
  cout << "Size of A = " << sizeof(class A) << "; Size of B = " << sizeof( B )
       << "; Size of f = " << sizeof( f ) << endl;
  return 1;   
  }

/**
 * Output:
A(0) created
B created
A(4745536) created
j is 7

Size of C = 16
Size of A = 1; Size of B = 1; Size of f = 24
 * 
 * struct/class is not exactly the sum of sizes of its constituents
 * A is 1 because it has nothing, but cannot be zero size.
 * C has 1 integer (4 bytes), etc.
 * Gary didn't talk about it :(
 * 
 * - byte alignment/padding
 * - compiler (sometimes references are implemented as pointers)
 * - virtual functions
 */