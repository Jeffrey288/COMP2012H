#include <iostream>
using namespace std;

class A {
public:
    A* j = nullptr;
    A(int i) { cout << "hey"; }
    ~A() {delete j; cout << "bye!";}
};

int square(int x) {return x * x;}
const int& square2(int x) {return x * x;}
void print_int(const int& x) {cout << "const int&: " << x << endl;}
void print_int(int&& x) {cout << "int&&: " << x << endl;}
void print_int(const int&& x) {cout << "const int&&: " << x << endl;}


int main() {
    int a = 3;
    // int& b = 4;
    const int& c = 5;
    int d = square(3);
    const int& e = square(3);
    const int& f = square(4) + e;
    const int& g = square(10);
    cout << g << endl;
    const int* h = &g;
    cout << *h << endl;
    int* i = const_cast<int *>(h);
    cout << *i << endl;
    int& j = *i;
    cout << j << endl;
    j = 200;
    cout << j << endl;
    cout << g << endl;
    print_int(g);
    int&& k = square(12);
    print_int(k);
    print_int(10);

    // A x;
    A *x = new A(1);
    delete x;
    x = nullptr;
    delete x;

    A& y = *x;
    cout << &y << endl;
    cout << "bye!" << endl;
}