#include "Warrior.h"

// Please do not change the following already implemented code

void Warrior::level_up()
{
    max_hp += 3;
    cur_hp = max_hp;
    atk += 2;
    def += 1;
    max_mp += 1;
    level += 1;
}

//write your code here
