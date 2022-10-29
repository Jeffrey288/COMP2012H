#include <iostream> /* afile.cpp */
using namespace std;
static int a;
int func();
int main() {
    a = 10;
    cout << a << " " << func() << endl;
    return 0;
}