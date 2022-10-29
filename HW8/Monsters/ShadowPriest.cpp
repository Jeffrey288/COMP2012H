#include "ShadowPriest.h"

ShadowPriest::ShadowPriest(int x, int y) : Monster(x, y)
{
    cur_hp = max_hp = 15;
    atk = 5, def = 2;
}

//write your code here

ShadowPriest::~ShadowPriest() {}

string ShadowPriest::get_monster_str() const {
    char buff[10];
    sprintf(buff, "%02d", cur_hp);
    return "S" + string(buff);
}

/*
void action(Player &p, MapUnit *map[][MAP_SIZE]) override
If the distance between the ShadowPriest unit and the player is no larger than 1, call Player::attacked_by(atk) to attack the player where atk is the ATK of this Warlock unit.
Then the ShadowPriest cure all its surrounding valid Monster units by adding 5 HPs to their current HP.
*/
#define HORZ_DISTANCE(x_1, y_1, x_2, y_2) abs((x_1) - (x_2))
#define VERT_DISTANCE(x_1, y_1, x_2, y_2) abs((y_1) - (y_2))
#define DISTANCE(x_1, y_1, x_2, y_2) (HORZ_DISTANCE(x_1, y_1, x_2, y_2) + VERT_DISTANCE(x_1, y_1, x_2, y_2))
void ShadowPriest::action(Player &p, MapUnit *map[][MAP_SIZE]) {
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
            if (px == x + c && py == y + r) continue;
            if (map[x+c][y+r]->get_unit_type() != UnitType::MONSTER) continue;
            static_cast<Monster*>(map[x+c][y+r])->recover_hp(5);
            // after making sure it is a monster we can use static_cast
            // to help us crash our program if my logic is wrong
        }
    }
}