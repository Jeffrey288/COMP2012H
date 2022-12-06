

#include <iostream>   // functor-lambda.cpp
#include <functional>
using namespace std;

struct A{
  int sum = 0, times = 0;
  void operator() ( int i = 0 )
  { sum += i; times++; }
};

template< class T > void g( int i, const T& t ){  t(i); }
template< class T > void g( int i, T& t ){ t(i); }

int main(){
  A a;
  for( int i = 0; i < 5; i++ )
    g(i, a);     // call the non-const T& version
  cout << "a's call times: " << a.times << "; sum: " << a.sum << endl;

  g( 7, [&a]( int i ){ cout << "lambda: " << (a.sum += i) << endl; }
     );  // call the const T& version
  return 1; }
// a's call times: 5; sum: 10
// lambda: 17

