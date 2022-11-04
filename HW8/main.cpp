#include "GameEngine.h"
#include <fstream>

using namespace std;

int main()
{
    // std::ofstream out("out.txt");
    // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt
    GameEngine ge;
    ge.run();
    return 0;
}