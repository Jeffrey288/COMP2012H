Source: https://gitlab.com/-/snippets/1788807

Good resource on vtables and slicing:
https://medium.com/geekculture/c-inheritance-memory-model-eac9eb9c56b5

```bash
g++ -o main main.cpp -Wall -fno-elide-constructors -std=c++11
```

vtable

main.cpp:24:9: warning: deleting object of abstract class type 'Foo' which has
non-virtual destructor will cause undefined behavior [-Wdelete-non-virtual-dtor]

main.cpp:5:9: error: constructors cannot be declared 'virtual' [-fpermissive]
main.cpp:12:17: error: 'Bar::Bar()' marked 'override', but does not override

main.cpp:22:32: error: invalid conversion from 'Base*' to 'Derived*' [-fpermissive]
main.cpp:16:13: error: cannot declare variable 'bar' to be of abstract type 'Bar'

notable exampls
q5
```C++
struct Foo {
	virtual ~Foo() = default;
	virtual void fun(int x) { cout << "funfoo: " << x << endl; }
};

struct Bar : public Foo {
	virtual void fun(double y) { cout << "funbar: " << y << endl; } // this hides Foo::fun(int x), but does not override it. If override keyword is added, will lead to error
    // main.cpp:10:22: error: 'virtual void Bar::fun(double)' marked 'override', but does not override

	// virtual void fun(int y) {cout << "funbarint: " << y << endl; } // this does override
};

int main() {
	Foo *bar = new Bar;
	bar->fun(0); // calls funfoo
	bar->fun(1.4); // calls funfoo
	Bar *realbar = new Bar;
	realbar->fun(2);
	realbar->fun(3.7);
	delete bar;
	delete realbar;
	return 0;
}
```

something
```C++
class Base {
  public:
    virtual int clone() const {
		cout << "baseclone" << endl;
    //   return new Base(*this); 
	return 1;
    }
};
class Derived : public Base {
  public:
    virtual float clone() const { // main.cpp:15:19: error: conflicting return type specified for 'virtual float Derived::clone() const'
		cout << "derivedclone" << endl;
      return 1.0;
    }
};
```

compiles in c++17, but not c++11
main.cpp:11:19: error: cannot convert 'Bar' to 'int'

```C++
struct Bar {
	explicit Bar() { cout << "default" << endl; }
	explicit Bar(const Bar &) { cout << "copy" << endl; }
	Bar(int x) { cout << "conv" << endl; }
};

int main() {
	Bar bar = Bar();
	return 0;
}
```

```C++

struct A { virtual void f() {cout << "A";} };
struct B : A { };
struct C : A { void f() {cout << "C";} };
struct D : B, C { }; // OK: A::f and C::f are the final overriders
// for the B and C subobjects, respectively

int main() {
	D().f(); // main.cpp:11:13: error: request for member 'f' is ambiguous
}
```

#### Different types of constructors
```C++
#include <iostream>
using namespace std;

class Bar {
public:
	explicit Bar() { cout << "default" << endl; }  // default constructor
	explicit Bar(const Bar &) { cout << "copy" << endl; } // copy constructor
//	Bar(Bar&& bar) { cout << "move" << endl; } // move constructor
	Bar(int x) { cout << "conv" << endl; } // conversion constructor
};

int main() {
    cout << "bar: " << endl;
    Bar bar = 5.3; // conv then copy
    cout << "bar2: " << endl;
    Bar bar2{Bar()}; // default then copy
    cout << "bar3: " << endl;
    Bar bar3(Bar()); // no output at all, 
	// Bar() is interpreted as a function pointer, bar3 is a function definition
	cout << "bar3_: " << endl;
	Bar bar3_(bar2); // copy
    cout << "bar4: " << endl;
    // Bar bar4 = Bar(); 
	cout << "bar4_: " << endl;
	// Bar bar4_ = bar2; // copy constructor is explicit, but this is implicit
    // This program:
    /* main.cpp:13:19: error: cannot convert 'Bar' to 'int' */
    // Remove explicit from default constructor,
    /* main.cpp:13:23: error: no matching function for call to 'Bar::Bar(Bar)' */
    // Compiles normally if move is uncommented or explicit from copy is removed
    // Uses move if move is present, else falls back to copy
	return 0;
}
```

```C++
class Bar {
public:
	int x;
	Bar() : x(0) { cout << this << "default " << x << endl; }
	Bar(int z) : x(z) { cout << this << "conversion " << x << endl; }
	Bar(const Bar &other) : x(other.x) { cout << this << "copy " << x << endl; }
	~Bar() { cout << this << "bye " << x << endl; }
};

void fun(int i) {
	static Bar bar = i; // conversion to temp object, then copied
	static Bar otherBar = {i + 1}; // conversion directly invoked
	bar = otherBar = i++; // conversion to temp object, then assign
	// (assignment operator is trivial)
	// cout << bar.x  << ", " << otherBar.x << endl;
}

int main() {
	cout << "main started" << endl;
	for (int i=2;i<5;i++) fun(i);
	cout << "main returning" << endl;
	return 0;
}
```

#### Aggregate types vs classes & brace-enclosed initializer lists
- remember bracket initalizers will cause narrowing conversion
- classes cannot be initalized like structs using initalizer lists
- any constructor defined will turn a struct into a "class"
```C++
struct Bar {
	double x;
	double y;
	Bar(int z) { x = z; cout << "conv" << endl; }
	// Bar(double z) { x = z; cout << "conv" << endl; }
};

int main() {
	// Bar is aggregate type without constructors
	// is not of any constructor is defined
	Bar bar = {3.5, 2.5}; // only works for aggregate type
	// else, could not convert from <brace-enclosed initializer list> to bar
	Bar bar2 = {2.5}; // *narrowing conversion* if int constructor is defined
	Bar bar3 = {2.5}; // same as bar2
	// bar2 and bar3 would invoke the Bar(double z) constructor if defined
	return 0;
}

```

Purpose of MIL: default values will not be defined

```C++
int main() {
	int x[]{2, 3, 5};
	int *z = x;
	cout << *x << " " << *(x + 1) << " " << *(x + 2) << endl;
	cout << "x: " << x << ", z: " << z << endl;
	cout << "&x: " << &x << endl;
	cout << "x == z: " << (x == z) << endl;
	// cout << "&x == z: " << (&x == z) << endl; 
	// error: comparison between distinct pointer types 'int (*)[3]' and 'int*' lacks a cast [-fpermissive]
	return 0;
}
```

```C++
int main() {
	int *x[2]{new int};
	delete x[0];
	delete x[1];
	return 0;
}
```

And by definition, numerically, we have `&x == x == &x[0]`.
```C++
int main() {
	const char (*c)[4] = &"bar";
	c++;
	cout << *c << endl;
	return 0;
}
```

From lecture notes,
```C++
class UPerson {};
class Student : public UPerson {};
void dance(const UPerson& p) {}; // Anyone can dance
void dance(const UPerson* p) {}; // Anyone can dance
void study(const Student& s) {}; // Only students study
void study(const Student* s) {}; // Only students study

int main() {

	UPerson p;
	Student s;
	dance(p);
	dance(s);
	dance(&p);
	dance(&s);
	study(s);
	study(p); // cannot compile: no matching function for call
	study(&s);
	study(&p); // cannot compile: invalid conversion from Uperson* to Student*
}
```

### Incomplete Type Error
Reference: https://stackoverflow.com/questions/44963201/when-does-an-incomplete-type-error-occur-in-c

Resolving:
- use a pointer to the struct as its size is always known
- include a header file containing the definition of the struct

```C++

struct Bar; // fowarded declaration
// however, definition is not yet given

struct Foo {
	Foo() { cout << "Me is foo!" << endl; }
	virtual ~Foo() { cout << "Foooooo!!! XoX" << endl; }
	friend int main() {
		Foo foo; Bar bar;
		// static declaration of struct Bar bar
		// leads to Incomplete Type error
		foo.x = bar.x = 2;
		return 0;
	}
	// Furthermore, definition of main within class will
	// inline it. However, main cannot be inlined. Hence,
	// undefined reference to main function will be raised.
private:
	int x;
};

struct Bar {
	Bar() { cout << "Me is bar!" << endl; }
	~Bar() { cout << "Barrrrrr!!! X_X" << endl; }
	friend int main();
private:
	int x;
};

```

main.cpp:8:9: error: templates may not be 'virtual'

```C++
template <typename T>
class Weird : public T {
public:
	Weird() { cout << "V Weird" << endl; }
	~Weird() { cout << "X Weird" << endl; }
	virtual void print() { T::print(); cout << T::MAGIC << " Weird" << endl; T::print(); }
};

class Foo {
private:
	static const int MAGIC = 3;
public:
	Foo() { cout << "V Foo" << endl; }
	virtual ~Foo() { cout << "X Foo" << endl; }
	virtual void print() { cout << "P Foo" << endl; }
	template <typename S>
	friend class Weird;
};

int main() {
	Foo *weirdFoo = new Weird<Weird<Foo>>;
	weirdFoo->print();
	delete weirdFoo;
	return 0;
}
// EXTRA: why is 'T::' in 'T::MAGIC' necessary?

```