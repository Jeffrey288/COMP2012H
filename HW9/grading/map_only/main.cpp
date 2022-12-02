#include <iostream>
#include <random>
#include "skiplist.hpp"

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

minstd_rand pa9_rand;

bool operator<(const string & lhs, const string & rhs) {
    return lhs.compare(rhs) < 0;
}

bool operator>(const string & lhs, const string & rhs) {
    return lhs.compare(rhs) > 0;
}

bool operator<=(const string & lhs, const string & rhs) {
    return lhs.compare(rhs) <= 0;
}

bool operator>=(const string & lhs, const string & rhs) {
    return lhs.compare(rhs) >= 0;
}

int square(int x) {return x*x;}

double half(int x) {return x / 2.0;}

bool posi(int x) {return x >= 0;}

bool eql(int x) {return x == 1;}

bool allFalse(string x) {return false;}



template <typename T>
struct myNode {
    T data;
    myNode() = default;
    myNode(T data) : data(data) {}
    friend ostream& operator<<(ostream& os, const myNode& node) {
        return (os << node.data);
    }
    friend myNode operator+(const myNode& node, const myNode& other) {
        return myNode(node.data + other.data);
    }
    friend bool operator==(const myNode& node, const myNode& other) {
        return node.data == other.data;
    }
};

int main() {

    pa9_rand = minstd_rand(2012);

    int test;
    cin >> test;

    if (test == 48) {
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing map() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.grade_update(1, 1);
        sl.grade_update(3, 3);
        sl.grade_update(7, 7);
    
        cout << "Mapped: ";
        sl.map(square).grade_print();

        cout << "Original: ";
        sl.grade_print();

    } else if (test == 49) {
        pa9_rand = minstd_rand(812941);
        Skiplist<string, int> sl("grading");
        string name = "Part I - Testing map() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
    
        cout << "Mapped: ";
        sl.map(half).grade_print();

        cout << "Original: ";
        sl.grade_print();

    } else if (test == 50) {
        pa9_rand = minstd_rand(812941);
        Skiplist<string, int> sl("grading");
        string name = "Part I - Testing map() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        for (int i = -100; i < 100; i += 21)
            sl.grade_update(to_string(i), i);

        cout << "Mapped: ";
        sl.map(half).grade_print();

        cout << "Original: ";
        sl.grade_print();

    }
    
    return 0;
}
    
    
    