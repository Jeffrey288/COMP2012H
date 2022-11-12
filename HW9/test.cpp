#include <cassert>
#include <iostream>
#include <random>

#include "object.hpp"
#include "skiplist.hpp"
constexpr int SIZE = 100000;
std::minstd_rand pa9_rand;

Skiplist<int, object> test_copy_move(Skiplist<int, object> x) {
    Skiplist<int, object> m = std::move(x);
    m = std::move(m);
    m = m;
    return m;
}

int main() {
    pa9_rand = std::minstd_rand(2012);
    Skiplist<int, int> composite;
    Skiplist<int, int> primes;
    Skiplist<int, int> factors;
    int temp;
    for (int i = 2; i < SIZE; i++) factors.update(i, 0);
    for (int i = 2; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j += i) {
            if (j < 2 || j >= SIZE) continue;
            factors.get(j, temp);
            factors.update(j, temp + 1);
        }
    }
    // factors.print();
    primes = factors.filter((bool (*)(int)) [](int x){return x == 1;});
    composite = factors.filter((bool (*)(int)) [](int x){return x > 1;});
    // primes.print();
    // composite.print();
    std::cout << primes.size() << std::endl; 
    Skiplist<int, bool> isPrime = factors.map((bool (*)(int)) [](int x){return x == 1;});
    isPrime = isPrime.filter((bool (*)(bool)) [](bool x){return x;});
    std::cout << isPrime.size() << std::endl; 
    assert(primes.size() == isPrime.size());
    assert(primes.size() + composite.size() == factors.size());
    assert((primes+composite).size() == factors.size());

    Skiplist<int, object> test;
    std::cout << "Testing update (insert)\n";
    for (int i = 0; i < SIZE; ++i) {
        test.update(i, i);
    }
    // test.print();
    for (int i = 0; i < SIZE; i++) {
        object temp;
        test.get(i, temp);
        test.update(SIZE - 1 - i, temp);
    }
    std::cout << "Testing copy and move\n";
    std::cout << test.size()  << std::endl;
    assert(test.size() == SIZE);
    int mysize = test_copy_move(test).size();
    std::cout <<  mysize << std::endl;
    assert(mysize == SIZE);
    std::cout << "Testing get\n";
    for (int i = 0; i < SIZE; ++i) {
        int a = pa9_rand() % SIZE;
        object x;
        assert(test.get(a, x));
        // std::cout<<x<<" "<<a<<std::endl;
        assert(object(abs(x.cast_back<int>()-((SIZE-1)/2.0))) == object(abs(a-((SIZE-1)/2.0))));
        assert(test.get(i, x));
        assert(abs(x.cast_back<int>()-((SIZE-1)/2.0)) == abs(i-((SIZE-1)/2.0)));
    }
    // test.print_full();
    std::cout << "Testing remove\n";
    assert(test.size() == SIZE);
    for (int i = 0; i < SIZE * 100; ++i) {
        int a = pa9_rand() % SIZE;
        test.remove(a);
    }
    std::cout << "Printing empty lists\n";
    // assert(test.size() == 0);
    // assert(test_copy_move(test).size() == 0);
    test.print_full();
    // test_copy_move(test).print_full();
    for (int i = 0; i < SIZE; ++i) {
        test.update(i, i);
    }
    int cnt = SIZE;
    for (int i = 0; i < SIZE; ++i) {
        cnt -= test.remove(pa9_rand() % SIZE);
    }
    assert(test.size() == cnt);
    std::cout << "end" << std::endl;
}