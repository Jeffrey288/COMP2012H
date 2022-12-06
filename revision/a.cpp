#include <iostream> /* afile.cpp */
using namespace std;
struct fuckboy {
    int a;
    int& operator[](int n) {return a; }
    fuckboy(int a) : a(a) {}
    // int operator[](int n) {return a; }
};

int main() {
    fuckboy fuck = {1};
    cout << fuck[1] << endl;
}