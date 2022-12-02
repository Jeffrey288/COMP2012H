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

    if (test == 1) {
        Skiplist<int, int>::Node node;
        string name = "Part I - Testing Node<int, int>() default constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "levels: " << node.levels << endl;
        bool n = true;
        for (int i = 0; i < node.levels; i++)
            n &= (node.nexts[i] == nullptr);
        cout << "is nullptr: " << boolalpha << n << endl;

    } else if (test == 2) {
        Skiplist<int, int>::Node node(2, 1, 2);
        string name = "Part I - Testing Node<int, int>() other constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "key: " << node.key << endl;
        cout << "value: " << node.value << endl;
        cout << "levels: " << node.levels << endl;
        bool n = true;
        for (int i = 0; i < node.levels; i++)
            n &= (node.nexts[i] == nullptr);
        cout << "is nullptr: " << boolalpha << n << endl;

    } else if (test == 3) {
        Skiplist<string, double>::Node node("test123", 0.5, 10);
        string name = "Part I - Testing Node<string, double>() other constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "key: " << node.key << endl;
        cout << "value: " << node.value << endl;
        cout << "levels: " << node.levels << endl;
        bool n = true;
        for (int i = 0; i < node.levels; i++)
            n &= (node.nexts[i] == nullptr);
        cout << "is nullptr: " << boolalpha << n << endl;

    } else if (test == 4) {
        Skiplist<int, int> sl;
        string name = "Part I - Testing Skiplist<int, int>() default constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.print_full();

    } else if (test == 5) {
        Skiplist<string, string> sl(0.33);
        string name = "Part I - Testing Skiplist<string, string>() default constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.print_full();

    } else if (test == 6) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        for (int i = 65; i < 75; i++)
            sl.update(i, i);

        cout << "After update:" << endl;
        sl.print_full();
        
    } else if (test == 7) {
        pa9_rand = minstd_rand(2211);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.update(10, 100);

        cout << "After update:" << endl;
        sl.print_full();
        
    } else if (test == 8) {
        pa9_rand = minstd_rand(21941912);
        Skiplist<string, int> sl("grading");
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.update("", 123);

        cout << "After update:" << endl;
        sl.print_full();
        
    } else if (test == 9) {
        pa9_rand = minstd_rand(21941912);
        Skiplist<string, double> sl("grading");
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.update("710", 10);
        sl.update("520", 10);
        sl.update("11", 11);
        sl.update("219", 19);
        sl.update("12", 12);
        sl.update("915", 15);
        sl.update("114", 14);
        sl.update("3", 18);
        sl.update("13", 13);

        cout << "After update:" << endl;
        sl.print_full();
        
    } else if (test == 10) {
        pa9_rand = minstd_rand(241912);
        Skiplist<string, int> sl("grading", 0.5);
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.update("10", 10);
        sl.update("20", 10);
        sl.update("11", 11);
        sl.update("19", 19);
        sl.update("12", 12);
        sl.update("15", 15);
        sl.update("14", 14);
        sl.update("18", 18);
        sl.update("13", 13);

        cout << "After update:" << endl;
        sl.print_full();
        
    } else if (test == 11) {
        pa9_rand = minstd_rand(24192);
        Skiplist<int, int> sl("grading", 0.5);
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.update(10, 10);
        sl.update(20, 10);
        sl.update(50, 1);
        sl.update(11, 11);
        
        cout << "After first update:" << endl;
        sl.print_full();
        cout << endl;

        sl.update(10, 11);
        sl.update(20, 50);

        cout << "After second update:" << endl;
        sl.print_full();

    } else if (test == 12) {
        pa9_rand = minstd_rand(241912);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing update() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 0; i < 100000; i++)
            sl.update(i, i);
        
        unsigned long long total = 0;
        for (int i = 0; i < 100000; i++) {
            int g;
            sl.grade_get(i, g);
            total += g;
        }
            
        cout << "Total sum: " << total << endl;
        cout << "Implementation correct by timing test." << endl;

    } else if (test == 13) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 75; i++)
            sl.grade_update(i, i);
        
        int rtn;
        bool a = sl.get('F', rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << rtn << endl;

    } else if (test == 14) {
        pa9_rand = minstd_rand(241912);
        Skiplist<string, char> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        char rtn = 0;
        bool a = sl.get("test", rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << static_cast<int>(rtn) << endl;

    } else if (test == 15) {
        pa9_rand = minstd_rand(241912);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 10; i < 100; i++)
            sl.grade_update(i, i*2);
        
        int rtn = 0;
        bool a = sl.get(58, rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << rtn << endl;

    } else if (test == 16) {
        pa9_rand = minstd_rand(241912);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 10; i < 100; i++)
            sl.grade_update(i, i*2);
        
        int rtn = 0;
        bool a = sl.get(-1, rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << rtn << endl;

    } else if (test == 17) {
        pa9_rand = minstd_rand(241912);
        Skiplist<string, string> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.grade_update("a", "5");
        sl.grade_update("b", "666");
        sl.grade_update("c", "78");
        sl.grade_update("d", "123");
        sl.grade_update("e", "990");
        sl.grade_update("f", "11");
        
        string rtn;
        bool a = sl.get("d", rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << rtn << endl;

    } else if (test == 18) {
        pa9_rand = minstd_rand(241912);
        Skiplist<string, string> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        string rtn;
        bool a = sl.get("", rtn);

        cout << "contains: " << boolalpha << a << endl;
        cout << "value: " << rtn << endl;

    } else if (test == 19) {
        pa9_rand = minstd_rand(241912);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 1; i < 11; i++)
            sl.grade_update(i, i);
        
        int total = 0;
        bool a = true;
        for (int i = 1; i < 11; i++) {
            int rtn = 0;
            a &= sl.get(i, rtn);
            total += rtn;

            rtn = 0;
            a &= sl.get(i, rtn);
            total += rtn;
        }
            
        cout << "contains: " << boolalpha << a << endl;
        cout << "total: " << total << endl;
        cout << endl;

    } else if (test == 20) {
        pa9_rand = minstd_rand(241912);
        Skiplist<string, bool (*)(int)> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.grade_update("posi", posi);
        sl.grade_update("eql", eql);
        
        bool (*my_func)(int);
        bool a = sl.get("posi", my_func);

        cout << "contains: " << boolalpha << a << endl;
        cout << "result: " << boolalpha << my_func(-10) << ", " << my_func(10) << endl;
        cout << endl;

    } else if (test == 21) {
        pa9_rand = minstd_rand(241912);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing get() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 0; i < 100000; i++)
            sl.grade_update(i, i);
        
        unsigned long long total = 0;
        for (int i = 0; i < 100000; i++) {
            int g;
            sl.get(i, g);
            total += g;
        }
            
        cout << "Total sum: " << total << endl;
        cout << "Implementation correct by timing test." << endl;

    } else if (test == 22) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 71; i++)
            sl.grade_update(i, i);

        cout << "contains: " << boolalpha << sl.remove('E') << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 23) {
        pa9_rand = minstd_rand(241112);
        Skiplist<string, int> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.grade_update("test", 1234);
        sl.grade_update("yata", 203);
        sl.grade_update("zzzz", 1323);

        cout << "contains: " << boolalpha << sl.remove("zzzz") << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 24) {
        pa9_rand = minstd_rand(241912);
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 69; i++)
            sl.grade_update(i, i);

        cout << "contains: " << boolalpha << sl.remove('B') << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 25) {
        pa9_rand = minstd_rand(24112);
        Skiplist<char, int> sl("grading", 0.4);
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 70; i++)
            sl.grade_update(i, i);

        cout << "contains: " << boolalpha << sl.remove('A') << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 26) {
        pa9_rand = minstd_rand(222012);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 1000; i < 1010; i++)
            sl.grade_update(i, i);

        cout << "contains: " << boolalpha << sl.remove(1004) << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 27) {
        pa9_rand = minstd_rand(24112);
        Skiplist<string, double> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        cout << "contains: " << boolalpha << sl.remove("") << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 28) {
        pa9_rand = minstd_rand(24112);
        Skiplist<int, double> sl("grading", 0.7);
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        sl.grade_update(0, 0.1);

        cout << "contains: " << boolalpha << sl.remove(0) << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 29) {
        pa9_rand = minstd_rand(24112);
        Skiplist<int, double> sl("grading", 0.5);
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        bool a = true;
        for (int i = 50; i < 101; i++)
            sl.grade_update(i, i/10.0);

        for (int i = 99; i >= 50; i--)
            a &= sl.remove(i);

        cout << "contains: " << boolalpha << a << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 30) {
        pa9_rand = minstd_rand(24112);
        Skiplist<short, double> sl("grading", 0.4);
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        for (int i = 1000; i < 1005; i++)
            sl.grade_update(i, i/10.0);

        cout << "contains: " << boolalpha << sl.remove(100) << endl;
        cout << "After remove:" << endl;
        sl.print_full();

    } else if (test == 31) {
        pa9_rand = minstd_rand(24112);
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing remove() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 0; i < 100000; i++)
            sl.grade_update(i, i);
        
        for (int i = 99999; i >= 1; i--)
            sl.remove(i);

        cout << "Remaining Skiplist:" << endl;
        sl.print_full();
        cout << "Implementation correct by timing test." << endl;

    } else if (test == 32) {
        Skiplist<int, int> sl1("grading");
        string name = "Part I - Testing Skiplist() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 5; i < 10; i++)
            sl1.grade_update(i, i);
        
        Skiplist<int, int> sl2(sl1);
        sl2.print_full();

    } else if (test == 33) {
        pa9_rand = minstd_rand(2841122);
        Skiplist<string, string> sl1("grading", 0.6);
        string name = "Part I - Testing Skiplist() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl1.grade_update("Mary", "1234");
        sl1.grade_update("Brian", "2534");
        sl1.grade_update("Desmond", "8867");
        sl1.grade_update("Tony", "1333");
        sl1.grade_update("Ben", "2242");
        
        Skiplist<string, string> sl2(sl1);

        cout << "Original Skiplist:" << endl;
        sl1.print_full();
        cout << endl;

        cout << "Copied Skiplist:" << endl;
        sl2.print_full();

    } else if (test == 34) {
        pa9_rand = minstd_rand(2841122);
        Skiplist<string, string> sl1("grading", 0.3);
        string name = "Part I - Testing Skiplist() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        Skiplist<string, string> sl2(sl1);

        cout << "Original Skiplist:" << endl;
        sl1.print_full();
        cout << endl;

        cout << "Copied Skiplist:" << endl;
        sl2.print_full();

    } else if (test == 35) {
        pa9_rand = minstd_rand(856897);
        Skiplist<string, float> sl1("grading", 0.4);
        string name = "Part I - Testing Skiplist() copy constructor";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl1.grade_update("Mary", 1234);
        sl1.grade_update("Brian", 2534);
        sl1.grade_update("Desmond", 8867);
        sl1.grade_update("Tony", 1333);
        sl1.grade_update("Ben", 2242);
        
        Skiplist<string, float> sl2(sl1);
        sl2.grade_update("Eden", 5325);
        sl2.grade_update("Sam", 5678);

        cout << "Original Skiplist:" << endl;
        sl1.print_full();
        cout << endl;

        cout << "New Skiplist:" << endl;
        sl2.print_full();

    } else if (test == 36) {
        Skiplist<int, int> sl1("grading"), sl2("grading");
        string name = "Part I - Testing operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 5; i < 10; i++)
            sl1.grade_update(i, i);
        
        sl2 = sl1;
        sl2.print_full();

    } else if (test == 37) {
        pa9_rand = minstd_rand(856897);
        Skiplist<string, int> sl1("grading", 0.4), sl2("grading", 0.6), sl3("grading", 0.7);
        string name = "Part I - Testing operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 5; i < 10; i++)
            sl1.grade_update(to_string(i), i);
        
        for (int i = 101; i < 110; i++)
            sl2.grade_update(to_string(i), i);

        sl3 = sl2 = sl1;

        cout << "First:" << endl;
        sl1.print_full();
        cout << endl;

        cout << "Second:" << endl;
        sl2.print_full();
        cout << endl;

        cout << "Third:" << endl;
        sl3.print_full();

    } else if (test == 38) {
        pa9_rand = minstd_rand(85897);
        Skiplist<int, string> sl("grading", 0.4);
        string name = "Part I - Testing operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 100; i < 105; i++)
            sl.grade_update(i, to_string(i));
        
        sl = sl;
        sl.grade_remove(102);
        sl.print_full();

    } else if (test == 39) {
        pa9_rand = minstd_rand(858397);
        Skiplist<string, float> sl1("grading", 0.5);
        string name = "Part I - Testing operator=() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl1.grade_update("Mary", 1234);
        sl1.grade_update("Brian", 2534);
        sl1.grade_update("Desmond", 8867);
        sl1.grade_update("Tony", 1333);
        sl1.grade_update("Ben", 2242);
        
        Skiplist<string, float> sl2("grading");
        sl2.grade_update("Eden", 5325);
        sl2.grade_update("Sam", 5678);
        sl2.grade_update("Tony", 4214);
        sl2.grade_update("Tom", 9893);

        sl2 = sl1;
        sl2.grade_update("Austin", 5682);
        sl2.grade_update("Anson", 9741);

        cout << "Original Skiplist:" << endl;
        sl1.print_full();
        cout << endl;

        cout << "New Skiplist:" << endl;
        sl2.print_full();

    } else if (test == 40) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing size() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 70; i++)
            sl.grade_update(i, i);
        
        cout << "size: " << sl.size() << endl;

    } else if (test == 41) {
        pa9_rand = minstd_rand(812941);
        Skiplist<string, size_t> sl("grading");
        string name = "Part I - Testing size() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "size: " << sl.size() << endl;

    } else if (test == 42) {
        pa9_rand = minstd_rand(812941);
        Skiplist<string, string> sl("grading");
        string name = "Part I - Testing size() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = -1; i > -75; i--)
            sl.grade_update(to_string(i), to_string(i));

        cout << "size: " << sl.size() << endl;
        
    } else if (test == 43) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing empty() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 70; i++)
            sl.grade_update(i, i);
        
        cout << "empty: " << boolalpha << sl.empty() << endl;

    } else if (test == 44) {
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing empty() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        cout << "empty: " << boolalpha << sl.empty() << endl;

    } else if (test == 45) {
        Skiplist<char, int> sl("grading");
        string name = "Part I - Testing print() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 65; i < 70; i++)
            sl.grade_update(i, i);
        
        sl.print();

    } else if (test == 46) {
        Skiplist<string, size_t> sl("grading");
        string name = "Part I - Testing print() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.print();

    } else if (test == 47) {
        pa9_rand = minstd_rand(812941);
        Skiplist<int, string> sl("grading");
        string name = "Part I - Testing print() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        for (int i = 1; i < 200; i = i*-2) 
            sl.grade_update(i, to_string(i*10));
        
        sl.print();

    } else if (test == 51) {
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing filter() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl.grade_update(1, 1);
        sl.grade_update(2, -5);
        sl.grade_update(3, 8);
        sl.grade_update(4, -10);

        cout << "Filtered: ";
        sl.filter(posi).grade_print();

        cout << "Original: ";
        sl.grade_print();

    } else if (test == 52) {
        Skiplist<int, int> sl("grading");
        string name = "Part I - Testing filter() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
            
        for (int i = 1; i < 11; i++)
            sl.grade_update(i + 10, i);

        cout << "Filtered: ";
        sl.filter([](int a) -> bool {return a % 10 == 0;}).grade_print();

        cout << "Original: ";
        sl.grade_print();

    } else if (test == 53) {
        pa9_rand = minstd_rand(8129411);
        Skiplist<size_t, string> sl("grading");
        string name = "Part I - Testing filter() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;

        for (size_t i = 3210; i < 3290; i += 9)
            sl.grade_update(i, to_string(i*8));

        cout << "Filtered: ";
        sl.filter(allFalse).grade_print();

        cout << "Original: ";
        sl.grade_print();

    } else if (test == 54) {
        Skiplist<int, int> sl1("grading"), sl2("grading");
        string name = "Part I - Testing operator+() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        sl1.grade_update(1, 1);
        sl1.grade_update(2, 2);
        sl1.grade_update(3, 3);

        sl2.grade_update(4, 4);

        (sl1 + sl2).grade_print();

    } else if (test == 55) {
        pa9_rand = minstd_rand(8129411);
        Skiplist<string, int> sl1("grading"), sl2("grading");
        string name = "Part I - Testing operator+() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 10000; i < 10050; i += 2)
            sl1.grade_update(to_string(i % 50), i);

        (sl1 + sl2).grade_print();
        
    } else if (test == 56) {
        pa9_rand = minstd_rand(812941);
        Skiplist<int, float> sl1("grading"), sl2("grading");
        string name = "Part I - Testing operator+() function";
        cout << IDX << test << NAME << name << endl
             << LINE << endl;
        
        for (int i = 10000; i < 10050; i += 2)
            sl1.grade_update(i - 20, i + 0.5);
        
        for (int i = 10000; i < 10015; i++)
            sl2.grade_update(i, i + 0.3);
        
        (sl1 + sl2).grade_print();
        
    } 
    
    return 0;
}
    
    
    