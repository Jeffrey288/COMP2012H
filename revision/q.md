# Answering Questions in Lecture Notes

### Lecture 12

(p58) Question: Why won’t polymorphism work if pass-by-value is used? \
A: pass by value will do slicing

(p68) Question: Can a virtual function be declared as protected or private in the derived classes (while it is declared as public in the base class)? \
A: can
```C++
class Base {
public:
    virtual void foo() {}
}

class Derived : public Base {
private:
    virtual void foo() override {}
}
```

(p104) Quiz: Why the first error mentions a ’const Student’ instead of a
’Student’?
A: 
```C++
UPerson p = ug;
// invokes conversion constructor
UPerson p(ug);
// uses default conversion constructor
UPerson& p(const Student&);
// Student's UPerson's region is protected
/* -> raises error
no-slicing.cpp:10:17: error: cannot cast 'const Student' to its
protected base class 'const UPerson'
    UPerson p = ug; // Allowed or not?
*/
```

(p106) Question: Does polymorphism (by overriding) work with protected/private inheritance?
E.g., for the UPerson example, try to derive Student or Teacher by protected or private inheritance.
A: go find out yourself (lmao)

```C++
class B {
private:
	virtual void base_print() { print(); };
	virtual void print() { cout << "Bprint" << endl; }
};

class D1 : private B {
public: // overrides normally
	virtual void print() override { cout << "D1print" << endl; }
};

class D2 : protected B {
public: // overrides normally
	virtual void print() override { cout << "D2print" << endl; }
};

int main() {
	B* b = new B;
	D1* d1 = new D1;
	D2* d2 = new D2;
	// b->print();
	d1->print();
	d2->print();
	return 0;
}
```