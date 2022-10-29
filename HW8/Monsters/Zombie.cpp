#include "Zombie.h"

Zombie::Zombie(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 20;
    atk = 9, def = 3;
}

//write your code here
Zombie::~Zombie() {}
string Zombie::get_monster_str() const {
    char buff[10];
    sprintf(buff, "%02d", cur_hp);
    return "Z" + string(buff);
}

#define HORZ_DISTANCE(x_1, y_1, x_2, y_2) abs((x_1) - (x_2))
#define VERT_DISTANCE(x_1, y_1, x_2, y_2) abs((y_1) - (y_2))
#define DISTANCE(x_1, y_1, x_2, y_2) (HORZ_DISTANCE(x_1, y_1, x_2, y_2) + VERT_DISTANCE(x_1, y_1, x_2, y_2))
void Zombie::action(Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    p.get_position(px, py);
    if (DISTANCE(x, y, px, py) <= 1) {
        p.attacked_by(atk);
    }
}

