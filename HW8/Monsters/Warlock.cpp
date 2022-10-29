#include "Warlock.h"

Warlock::Warlock(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 15;
    atk = 5, def = 1;
}

//write your code here

Warlock::~Warlock() {}

string Warlock::get_monster_str() const {
    char buff[10];
    sprintf(buff, "%02d", cur_hp);
    return "W" + string(buff);
}

/*
void action(Player &p, MapUnit *map[][MAP_SIZE]) override
If the distance between the Warlock unit and the player is no larger than 1, call Player::attacked_by(atk) to attack the player where atk is the ATK of this Warlock unit.
Then the Warlock unit change its surrounding map units into Zombie units if:
the map unit is not blocked, and
the player is not on that map unit.
As is shown in the figure below, the surrounding map units of the red map unit is the blue map units.
*/
#define HORZ_DISTANCE(x_1, y_1, x_2, y_2) abs((x_1) - (x_2))
#define VERT_DISTANCE(x_1, y_1, x_2, y_2) abs((y_1) - (y_2))
#define DISTANCE(x_1, y_1, x_2, y_2) (HORZ_DISTANCE(x_1, y_1, x_2, y_2) + VERT_DISTANCE(x_1, y_1, x_2, y_2))
void Warlock::action(Player &p, MapUnit *map[][MAP_SIZE]) {
    int px, py;
    p.get_position(px, py);
    if (DISTANCE(x, y, px, py) <= 1) {
        p.attacked_by(atk);
    }
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) continue;
            if (!((0 <= x + c && x + c < MAP_SIZE) && (0 <= y + r && y + r < MAP_SIZE)))
                continue;
            if (map[x+c][y+r]->is_blocked()) continue;
            if (px == x + c && py == y + r) continue;
            delete map[x+c][y+r];
            map[x+c][y+r] = new Zombie(x+c, y+r);
        }
    }
}

