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

/* Initialize a Player of Warrior at (x_, y_)
    with name as name_. 
    Initialize the atk = 6, def = 3, cur_hp = max_hp = 15.
*/
Warrior::Warrior(int x_, int y_, const string &name_) 
    : Player(x_, y_, name_) { 
        // cannot use MIL for atk, def, etc. Why?
        // Hypothesis: because defined before consturctor of Player
        atk = 6;
        def = 3;
        cur_hp = max_hp = 15;
    }

Warrior::~Warrior() {
    // TODO!
}

Role Warrior::get_role() const {
    return Role::WARRIOR;
}

int Warrior::get_range() const {
    return 1;
}

int Warrior::skill(int &atk, int &range) {
    return 1;
}

/*
Compute the damage as damage = atk_ - def, where atk_ is is the incoming attack point and def is the defence of the player. Then:
If the damage is larger than or equal to current HP of the Warrior player, and current MP is larger than 0, consume 1 MP, such that the damage won't take effect, and recover HP of max_hp/2. Return.
Else if the damage is larger than 0, cur_hp = cur_hp - damage.
Return.
*/
void Warrior::attacked_by(int atk_) {
    int damage = atk_ - def; // can be negative cuz def > atk_
    if (damage >= cur_hp && cur_mp > 0) {
        cur_mp -= 1; // must >= 0
        recover_hp(max_hp / 2);
    } else if (damage > 0) {
        cur_hp = cur_hp - damage; // allow it to drop below zero
    }
}