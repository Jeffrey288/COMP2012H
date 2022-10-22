#include "Mage.h"

// Please do not change the following already implemented code
void Mage::level_up()
{
    max_hp += 2;
    cur_hp = max_hp;
    atk += 2;
    def += 2;
    max_mp += 1;
    level += 1;
    max_exp += 2;
}

//write your code here
