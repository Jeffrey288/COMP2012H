#include <iostream>
using namespace std;

int main() {
    int a = 4, b = 5, c = 6;
    // [](int x, int y, int z) { x = y; y = z; z = x; } (a, b, c);
    [=]() mutable {a = b; b=c;c=a;}();
    cout << a << b << c << endl;

}