#include <iostream>
#include <random>

#include "object.hpp"
#include "skiplist.hpp"
std::minstd_rand pa9_rand;

int main() {
    pa9_rand = std::minstd_rand(2012);
    Skiplist<int, int> list;
    while (1) {
        std::cout << "Select the following: " << std::endl
            << "";
        int choice;
        std::cin >> choice;
        
    }
    
}