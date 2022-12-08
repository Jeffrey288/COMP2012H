#include <iostream>     // fptr-prototype.cpp
using namespace std;

class A{
public:
  A(){ cout << "default\n"; }
};

int main(){

  A a;  // cout default
  A();  // cout default; same as A{};
  A b{ A() };  // curly braces outside; cout default
  A c( A{} );  // curly braces inside; cout default
  A d{ A{} };  // curly braces inside and outside; cout default
  A e( A() );  // cout nothing because it is of A (A (*)()) prototype
       // same effect as A e( A () ), A e( A (*)() ) or A e( A (*f)() )
  A f( A (int, double) );  // cout nothing; unnamed function ptr

  // A (int, int); //compilation error
  // A (*)(int, int); // function ptr is unnamed; same as A (*f)(int, int)
  A g(int, int); // function g declaration/ function prototype

  return 1;
}
