#include "Archer.h"

// Please do not change the following already implemented code
void Archer::level_up()
{
    max_hp += 2;
    cur_hp = max_hp;
    atk += 3;
    def += 2;
    max_mp += 1;
    level += 1;
    max_exp += 2;
}

//write your code here
