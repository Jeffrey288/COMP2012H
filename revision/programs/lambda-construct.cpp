/**
 * 4/11/2022
 * 
 * 3) lambda-construct.cpp, showing the call of copy constructor of an
object which is captured.
 */

#include <iostream>      // lambda-construct.cpp
using namespace std;

struct bar{
  int i = 13;
  bar(){ cout << "bar constructor\n"; }
  bar(const bar& b){ i = b.i; cout << "bar copy constructor\n"; }
};

int main(){
  int a = 1, b = 2;
  bar c;  // bar constructor is called

  //  auto g = [a,c]() mutable {  // bar's copy constructor is called
  //    cout << ++a << " " << ++c.i << endl; }; 
  auto g = [=]() mutable { // bar's copy constructor is called
    cout << "lambda g: " << a << "(a); " << ++b << "(++b); "
    << ++c.i << "(++c.i) \n\n" ;
  }; 

  cout << "before invoking g" << endl;
  a = 10; g();
  cout << "c.i after calling g = " << c.i << "\n\n";
    for (int i =0; i<3; i++)
    g();

  // cout << [a](int x) {return a+= x; }(20) << endl; // no, as a is not mutable
  
  for (int i =0; i<3; i++)
  cout << "b += x in lambda, with x = 20: " <<
    [b](int x) mutable {return b += x; }(20) << endl;
  cout << "a and b in main body: " << a << " " << b << "\n\n";
  return 0; }

/**
 * Output:
bar constructor
bar copy constructor
before invoking g // constructors are invoked when g is constructed
lambda g: 1(a); 3(++b); 14(++c.i) // note that a is not changed to 10
lambda g: 1(a); 4(++b); 15(++c.i)

lambda g: 1(a); 5(++b); 16(++c.i)

lambda g: 1(a); 6(++b); 17(++c.i) 
  // note that b and c.i are changed within the lambda "object"
  // with subsequent calls

c.i after calling g = 13

b += x in lambda, with x = 20: 22
b += x in lambda, with x = 20: 22
b += x in lambda, with x = 20: 22 // b is changed in g, but kept the same
a and b in main body: 10 2 // not changed due to g
 */