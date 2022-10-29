#include "Monster.h"
#include <cmath>

// write your code here
Monster::Monster(int x, int y) 
    : MapUnit(x, y) {

}

Monster::~Monster() {}

bool Monster::is_active() const {
    return active;
}

void Monster::set_active() {
    if (is_valid()) {
        active = true;
    }
}

void Monster::recover_hp(int hp) {
    cur_hp += hp;
    if (cur_hp > max_hp) cur_hp = max_hp;
}

UnitType Monster::get_unit_type() const {
    return UnitType::MONSTER;
}

bool Monster::is_blocked() const {
    return is_valid();
}

int Monster::attacked_by(int atk_) {
    if (is_valid()) {
        int damage = atk_ - def;
        if (damage < 0) return 0;
        cur_hp -= damage;
        if (cur_hp <= 0) {
            invalidate();
            active = false;
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

string Monster::get_display_str() const {
    if (is_valid()) {
        if (!is_discovered()) {
            return SYM_DANGER;
        } else {
            return get_monster_str();
        }
    } else {
        return SYM_EMPTY;
    }
}


#define HORZ_DISTANCE(x_1, y_1, x_2, y_2) abs((x_1) - (x_2))
#define VERT_DISTANCE(x_1, y_1, x_2, y_2) abs((y_1) - (y_2))
#define DISTANCE(x_1, y_1, x_2, y_2) (HORZ_DISTANCE(x_1, y_1, x_2, y_2) + VERT_DISTANCE(x_1, y_1, x_2, y_2))
#define SIGN(val) (((val) > 0) ? 1 : -1)
#include <iostream>
void Monster::follow(const Player &p, MapUnit *map[][MAP_SIZE]) {
    // std::cout << "I was called!";
    int px, py, next_x, next_y;
    p.get_position(px, py);
    // std::cout << DISTANCE(x, y, px, py);
    if (DISTANCE(x, y, px, py) == 1) return;

    bool returnFlag = true;
    // test horizontal
    next_x = x + SIGN(px - x); next_y = y;
    if (HORZ_DISTANCE(x, y, px, py) > 0 // horz dist > 0
        && (next_x >= 0 && next_x < MAP_SIZE && !map[next_x][next_y]->is_blocked()) ) {  // not blocked
        returnFlag = false;
    } else {
        next_x = x; next_y = y + SIGN(py - y); 
        if (VERT_DISTANCE(x, y, px, py) > 0 // horz dist > 0
            && (next_y >= 0 && next_y < MAP_SIZE && !map[next_x][next_y]->is_blocked()) ) {  // not blocked
            returnFlag = false;
        }
    }
    // test vertical
    if (returnFlag) return;
    // move
    delete map[next_x][next_y];
    map[next_x][next_y] = this;
    map[x][y] = new EmptyLand(x, y);
    x = next_x; y = next_y;    
}