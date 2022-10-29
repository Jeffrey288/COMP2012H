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
/*
Initialize a Player of Archer at (x_, y_) with name as name_. Initialize the atk = 4, def = 3, cur_hp = max_hp = 12.
*/
Archer::Archer(int x_, int y_, const string &name_) 
    : Player(x_, y_, name_) {
    atk = 4;
    def = 3;
    cur_hp = max_hp = 12;
}

Archer::~Archer() {
    // TODO
}

Role Archer::get_role() const {
    return Role::ARCHER;
}

int Archer::get_range() const {
    return 3;
}

/*
If current MP is larger than 0, consume 1 MP and assign MAX_ATK to atk_, assign 3 to range and return 0.
Else, return 1.
*/
int Archer::skill(int &atk_, int &range) {
    if (cur_mp > 0) {
        cur_mp -= 1;
        atk_ = MAX_ATK; // good idea lol
        range = 3;
        return 0;
    } else {
        return 1;
    }
};