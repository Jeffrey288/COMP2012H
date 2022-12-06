#include <iostream>  // template_class.cpp
using namespace std;

template< class K, class V >
class foo{
public:
  struct bar{ K k; V v; };
  bar * bp = nullptr;
  ~foo(){ delete bp; }
  foo( K k, V v ); // constructor
  foo& operator=( const foo<K, V> & f );  // assignment
  const bar & return_bar( K k, V v );     // member function
};

template< class K, class V >
foo<K, V>::foo(K k, V v){
  bp = new bar;  bp -> k = k;  bp -> v = v;
}

template< class K, class V >
foo<K, V> & foo<K, V>::operator=( const foo< K,V > &f ){
  if( this != &f ){
    delete bp;
    bp = new typename foo< K, V>::bar;
    *bp = *(f.bp);
  }
  return *this;
}

template< class K, class V >
const class foo<K, V>::bar& foo<K, V>::return_bar( K k, V v){
  bp -> k = k;
  bp -> v = v;
  return *bp;
}

template< class K, class V >
class foo< K, V >::bar * function(K k, V v){
  class foo< K, V >::bar *b;
  b = new typename foo< K, V >::bar;
  b -> k = k;
  b -> v = v;
  return b;
}

int main(){
  foo< int, double > f( 10, 2.5 );
  cout << f.bp->k << " " << f.bp->v << endl;

  foo< int, double > g( 7, 3.9 );
  cout << g.bp->k << " " << g.bp->v << endl;

  f = g;
  cout << f.bp->k << " " << f.bp->v << endl;
  
  foo< int, double >::bar b;
  b.k = 9;
  b.v = 3.5;
  cout << b.k << " " << b.v << endl;

  b = f.return_bar( 4, 4.7);
  cout << b.k << " " << b.v << endl;

  foo< int, double >::bar *bptr = function(5, 7.7) ;
  cout << bptr -> k << " " << bptr -> v << endl;
  delete bptr;
  bptr = nullptr;
  
  return 1;
}
