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
/*
Initialize a Player of Mage at (x_, y_) with name as name_. Initialize the atk = 4, def = 2, cur_hp = max_hp = 15.
*/
Mage::Mage(int x_, int y_, const string &name_)
    : Player(x_, y_, name_) {
        atk = 4;
        def = 2;
        cur_hp = max_hp = 15;
        // atk = 14;
        // def = 2;
        // cur_hp = max_hp = 150;
}

Mage::~Mage() {
}

Role Mage::get_role() const {
    return Role::MAGE;
}

int Mage::get_range() const {
    return 2;
}

/*
If current MP is larger than 0, consume 1 MP and assign atk * 2 to atk_, assign 2 to range, recover HP of atk points and return 0.
Else, return 1.
*/
int Mage::skill(int &atk_, int &range) {
    if (cur_mp > 0) {
        cur_mp -= 1;
        atk_ = atk * 2;
        range = 2;
        cur_hp += atk;
        if (cur_hp > max_hp) cur_hp = max_hp;
        return 0;
    } else {
        return 1;
    }
}