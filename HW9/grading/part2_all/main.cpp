#include <iostream>
#include <random>
#include "object_replaced.hpp"

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

    if (test == 57) {
        object a(1);
        string name = "Part II - Testing object() conversion constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
            
        cout << "value: " << a.get_value<int>() << endl;

    } else if (test == 58) {
        object a(5.5);
        string name = "Part II - Testing object() conversion constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
            
        cout << "value: " << a.get_value<double>() << endl;
    
    } else if (test == 59) {
        object a(string("Haha"));
        string name = "Part II - Testing object() conversion constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
            
        cout << "value: " << a.get_value<string>() << endl;

    } else if (test == 60) {
        object a(myNode<int>(9876));
        string name = "Part II - Testing object() conversion constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
            
        cout << "value: " << a.get_value<myNode<int>>() << endl;

    } else if (test == 61) {
        object a(8.3);
        string name = "Part II - Testing object() conversion constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b(string("This is a test string"));
        object c(myNode<string>("myNode test cout"));
            
        cout << "a value: " << a.get_value<double>() << endl;
        cout << "b value: " << b.get_value<string>() << endl;
        cout << "c value: " << c.get_value<myNode<string>>().data << endl;

    } else if (test == 62) {
        object a("grading", 10);
        string name = "Part II - Testing object() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b = a;
        cout << "value: " << b.get_value<int>() << endl;
        
    } else if (test == 63) {
        object a("grading", string("123"));
        string name = "Part II - Testing object() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b = a;
        cout << "value: " << b.get_value<string>() << endl;
        
    } else if (test == 64) {
        object a("grading", myNode<int>(1267));
        string name = "Part II - Testing object() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b = a;
        cout << "value: " << b.get_value<myNode<int>>() << endl;
        
    } else if (test == 65) {
        object a("grading", 10);
        string name = "Part II - Testing object operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b("grading", 0);
        b = a;
        cout << "a value: " << a.get_value<int>() << endl;
        cout << "b value: " << b.get_value<int>() << endl;
    
    } else if (test == 66) {
        object a("grading", string("123"));
        string name = "Part II - Testing object operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b("grading", string("5678"));
        a = b;
        cout << "a value: " << a.get_value<string>() << endl;
        cout << "b value: " << b.get_value<string>() << endl;
    
    } else if (test == 67) {
        object a("grading", string("Haha"));
        string name = "Part II - Testing object operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b("grading", 2);
        a = b;
        cout << "a value: " << a.get_value<int>() << endl;
        cout << "b value: " << b.get_value<int>() << endl;
    
    } else if (test == 68) {
        object a("grading", 1);
        string name = "Part II - Testing object operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b("grading", 2.5);
        object c("grading", string("Test"));
        a = b = c;
        cout << "a value: " << a.get_value<string>() << endl;
        cout << "b value: " << b.get_value<string>() << endl;
        cout << "c value: " << c.get_value<string>() << endl;
    
    } else if (test == 69) {
        object a("grading", 1);
        string name = "Part II - Testing object operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        object b("grading", 10);
        a = a;
        a = b;
        cout << "a value: " << a.get_value<int>() << endl;
        cout << "b value: " << b.get_value<int>() << endl;
    
    } else if (test == 70) {
        object a("grading", 1);
        string name = "Part II - Testing object type() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "type is int: " << boolalpha << (a.type() == typeid(int)) << endl;
        
    } else if (test == 71) {
        object a("grading", string("String"));
        string name = "Part II - Testing object type() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "type is string: " << boolalpha << (a.type() == typeid(string)) << endl;
        
    } else if (test == 72) {
        object a("grading", myNode<string>("97913"));
        string name = "Part II - Testing object type() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "type is myNode<string>: " << boolalpha << (a.type() == typeid(myNode<string>)) << endl;
        
    } else if (test == 73) {
        object a("grading", (float) 1.9);
        string name = "Part II - Testing object type() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "type is float: " << boolalpha << (a.type() == typeid(float)) << endl;
        
    } else if (test == 74) {
        object a("grading", 100);
        string name = "Part II - Testing object cast_back() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "cast back to int: " << a.cast_back<int>() << endl;
        
    } else if (test == 75) {
        object a("grading", string("Test 123"));
        string name = "Part II - Testing object cast_back() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "cast back to string: " << a.cast_back<string>() << endl;
        
    } else if (test == 76) {
        object a("grading", myNode<double>(89.7));
        string name = "Part II - Testing object cast_back() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "cast back to myNode<double>: " << a.cast_back<myNode<double>>() << endl;
        
    } else if (test == 77) {
        object a("grading", 75.9);
        string name = "Part II - Testing object cast_back() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        try {
            cout << "cast back to string: " << a.cast_back<string>() << endl;
        } catch (std::runtime_error &e) {
            cout << e.what() << endl;
        }
        
    } else if (test == 78) {
        object a("grading", myNode<float>(1.23));
        string name = "Part II - Testing object cast_back() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        try {
            cout << "cast back to myNode<double>: " << a.cast_back<myNode<double>>() << endl;
        } catch (std::runtime_error &e) {
            cout << e.what() << endl;
        }
        
    }
    
    return 0;
}
    
    
    