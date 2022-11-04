#include "GameEngine.h"

using namespace std;

// Please do not change the following already implemented code

void GameEngine::print_active_monsters()
{
    int i = 0;
    cout << "Active Monsters:" << endl;
    MonsterNode *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data->get_display_str();
        cout << "@(" << cur->data->get_x();
        cout << "," << cur->data->get_y() << "), ";
        cur = cur->next;
        i++;
        if (i == 4)
        {
            i = 0;
            cout << endl;
        }
    }
}

bool GameEngine::player_win() const
{
    int px, py;
    player->get_position(px, py);
    if (px == MAP_SIZE - 1 && py == MAP_SIZE - 1)
    {
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                if (map[i][j]->get_unit_type() == UnitType::MONSTER && map[i][j]->is_valid())
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

GameEngine::GameEngine()
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (i > 8 && i < 12 && j > 2 && j < 6)
                map[i][j] = new Wall(i, j);
            else if (i > 14 && i < 18 && j > 2 && j < 6)
                map[i][j] = new Grass(i, j);
            else if (i > 2 && i < 6 && j == 9)
                map[i][j] = new Gem(i, j, GemType::RUBY);
            else if (i > 2 && i < 6 && j == 10)
                map[i][j] = new Gem(i, j, GemType::EMERALD);
            else if (i > 2 && i < 6 && j == 11)
                map[i][j] = new Gem(i, j, GemType::SAPPHIRE);
            else if (i > 8 && i < 12 && j > 8 && j < 12)
                map[i][j] = new Book(i, j);
            else if (i > 14 && i < 18 && j > 8 && j < 12)
                map[i][j] = new Medicine(i, j);
            else if (i > 2 && i < 6 && j > 14 && j < 18)
                map[i][j] = new Zombie(i, j);
            else if (i > 8 && i < 12 && j > 14 && j < 18)
                map[i][j] = new Warlock(i, j);
            else if (i > 14 && i < 18 && j > 14 && j < 18)
                map[i][j] = new ShadowPriest(i, j);
            else
                map[i][j] = new EmptyLand(i, j);
        }
    }
}

char GameEngine::input()
{
    char c;
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    return c;
}

void GameEngine::run()
{
    string name;
    cout << "Please enter your name:" << endl;
    cin >> name;
    cout << "Please choose your role:" << endl;
    cout << "1 Warrior" << endl;
    cout << "2 Archer" << endl;
    cout << "3 Mage" << endl;

    int x = 0, y = 0;
    char role = input();
    switch (role)
    {
    case '1':
        create_player(x, y, name, Role::WARRIOR);
        break;
    case '2':
        create_player(x, y, name, Role::ARCHER);
        break;
    case '3':
        create_player(x, y, name, Role::MAGE);
        break;
    default:
        exit(0);
        break;
    }
    ui.refresh(this->map, *player);

    while (true)
    {
        switch (input())
        {
        case 'w':
            this->player_move(Direction::UP);
            break;
        case 'a':
            this->player_move(Direction::LEFT);
            break;
        case 's':
            this->player_move(Direction::DOWN);
            break;
        case 'd':
            this->player_move(Direction::RIGHT);
            break;
        case 'h':
            this->player_attack();
            break;
        case 'j':
            this->player_skill();
            break;
        default:
            break;
        }
        if (player_win())
        {
            cout << endl;
            cout << "You win." << endl;
            break;
        }
        player_discover();
        activate_monsters();
        monster_follow();
        monster_act();
        ui.refresh(this->map, *player);
        print_active_monsters();
        if (!player->is_alive())
        {
            cout << endl;
            cout << "You lose." << endl;
            break;
        }
    }
}


// write your code here
GameEngine::~GameEngine() { 
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            delete map[c][r];
        }
    }
    if (head) {
        MonsterNode* thisNode = head;   
        MonsterNode* nextNode = thisNode->next;
        while (thisNode) {
            delete thisNode;
            thisNode = nextNode;
            if (thisNode) nextNode = thisNode->next;
        }
    }
    delete player;
}

void GameEngine::create_player(int x, int y, const string &name, Role role) {
    switch (role) {
        case Role::ARCHER:
            player = new Archer(x, y, name);
            break;
        case Role::MAGE:
            player = new Mage(x, y, name);
            break;        
        case Role::WARRIOR:
            player = new Warrior(x, y, name);
            break;
    }
}

void GameEngine::activate_monster(Monster *monster) {
    if (monster->is_valid() && !monster->is_active()) {
        monster->set_active();
        MonsterNode* newNode = new MonsterNode; // set up new node
        newNode->data = monster;

        newNode->next = head;
        head = newNode;
    }
}

/*
Activate the Monster units in the surrounding (-1 ≤ x ≤ 1, -1 ≤ y ≤ 1, where the player is at (x, y)) of the playe
*/
#define HORZ_DISTANCE(x_1, y_1, x_2, y_2) abs((x_1) - (x_2))
#define VERT_DISTANCE(x_1, y_1, x_2, y_2) abs((y_1) - (y_2))
#define DISTANCE(x_1, y_1, x_2, y_2) (HORZ_DISTANCE(x_1, y_1, x_2, y_2) + VERT_DISTANCE(x_1, y_1, x_2, y_2))
void GameEngine::activate_monsters() {
    int px, py;
    player->get_position(px, py);
    for (int c = -1; c <= 1; c++) {
        for (int r = -1; r <= 1; r++) {
            if (r == 0 && c == 0) continue;
            if (!((0 <= px + c && px + c < MAP_SIZE) && (0 <= py + r && py + r < MAP_SIZE)))
                continue;
            if (map[px+c][py+r]->get_unit_type() != UnitType::MONSTER) continue;
            activate_monster(static_cast<Monster*>(map[px+c][py+r]));
            // after making sure it is a monster we can use static_cast
            // to help us crash our program if my logic is wrong
        }
    }
}

void GameEngine::deactivate_monster(Monster const *const monster) { 
    MonsterNode* prevNode = nullptr;
    MonsterNode* curNode = head;
    for (; curNode && curNode->data != monster; prevNode = curNode, curNode = prevNode->next);
    if (curNode) {
        if (prevNode) { // has previous node
            prevNode->next = curNode->next;
        } else { // is the first node
            head = curNode->next;
        }
        delete curNode;
    }
}

void GameEngine::player_move(Direction d) {
    int dest_x, dest_y, px, py;
    player->get_position(px, py);
    switch (d) {
        case Direction::UP:
            dest_x = px; dest_y = py + 1;
            break;
        case Direction::DOWN:
            dest_x = px; dest_y = py - 1;
            break;
        case Direction::LEFT:
            dest_x = px - 1; dest_y = py;
            break;
        case Direction::RIGHT:
            dest_x = px + 1; dest_y = py;
            break;      
    }
    if (
        (dest_x < 0 || dest_x >= MAP_SIZE || dest_y < 0 || dest_y >= MAP_SIZE)
        || (map[dest_x][dest_y]->is_blocked())
    ) {
        player->move(d, 0);
        map[px][py]->triggered_by(*player);
    } else {
        player->move(d, 1);
        map[dest_x][dest_y]->triggered_by(*player);
    }

}

void GameEngine::player_discover() {
    int px, py;
    player->get_position(px, py);
    for (int r = -2; r <= 2; r++) {
        for (int c = -2; c <= 2; c++) {
            if (r == 0 && c == 0) continue;
            if (!((0 <= px + c && px + c < MAP_SIZE) && (0 <= py + r && py + r < MAP_SIZE)))
                continue;
            map[px+c][py+r]->set_discovered();
        }
    }
}

typedef struct {
    int x;
    int y;
} Vec2;
void GameEngine::player_attack() {

    int atk, def;
    player->get_atk_def(atk, def);
    int range = player->get_range();

    // constant code with the function below
    int px, py, dest_x, dest_y;
    player->get_position(px, py);
    Direction facing = player->get_direction();

    Vec2* dest_pos = new Vec2[range];
    switch (facing) {
        case Direction::UP:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px;
                dest_pos[r].y = py + 1 + r;
            }
            break;
        case Direction::DOWN:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px;
                dest_pos[r].y = py - 1 - r;
            }
            break;
        case Direction::LEFT:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px - 1 - r;
                dest_pos[r].y = py;
            }
            break;
        case Direction::RIGHT:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px + 1 + r;
                dest_pos[r].y = py;
            }
            break;      
    }

    for (int r = 0; r < range; r++) {
        if (!((0 <= dest_pos[r].x && dest_pos[r].x < MAP_SIZE) && (0 <= dest_pos[r].y && dest_pos[r].y < MAP_SIZE)))
                continue;
        int res = map[dest_pos[r].x][dest_pos[r].y]->attacked_by(atk);
        if (map[dest_pos[r].x][dest_pos[r].y]->get_unit_type() == UnitType::MONSTER) {
            Monster* monster = static_cast<Monster*>(map[dest_pos[r].x][dest_pos[r].y]);
            if (res > 0) {
                deactivate_monster(monster);
                player->gain_exp(1);
            } else if (res == 0 && !monster->is_active()) {
                activate_monster(monster);
                monster->set_discovered();
            }
        }
    }
    delete dest_pos;
}

/*
If the skill is not successfully used (Player::skill() returns 1), do nothing and return directly.
Else attack the map units using the atk and range specified by the Player::skill() function, similar to the player_attack() function. If an attacked map unit is monster unit:
If the monster is defeated by this attack (MapUnit::attacked_by() return value > 0), deactivate that monster (by calling deactivate_monster()), and the player will gain 1 EXP (by calling Player::gain_exp())
If the monster is not defeated by this attack (still valid, MapUnit::attacked_by() return value = 0), and the monster is not active, mark that monster as active and add it to the active monsters list.
*/
void GameEngine::player_skill() {
    int atk, range;
    range = player->get_range();
    int res = player->skill(atk, range);
    if (res == 1) return;

    // exact same thing
    int px, py, dest_x, dest_y;
    player->get_position(px, py);
    Direction facing = player->get_direction();

    Vec2* dest_pos = new Vec2[range];
    switch (facing) {
        case Direction::UP:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px;
                dest_pos[r].y = py + 1 + r;
            }
            break;
        case Direction::DOWN:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px;
                dest_pos[r].y = py - 1 - r;
            }
            break;
        case Direction::LEFT:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px - 1 - r;
                dest_pos[r].y = py;
            }
            break;
        case Direction::RIGHT:
            for (int r = 0; r < range; r++) {
                dest_pos[r].x = px + 1 + r;
                dest_pos[r].y = py;
            }
            break;      
    }

    for (int r = 0; r < range; r++) {
        if (!((0 <= dest_pos[r].x && dest_pos[r].x < MAP_SIZE) && (0 <= dest_pos[r].y && dest_pos[r].y < MAP_SIZE)))
                continue;
        int res = map[dest_pos[r].x][dest_pos[r].y]->attacked_by(atk);
        if (map[dest_pos[r].x][dest_pos[r].y]->get_unit_type() == UnitType::MONSTER) {
            Monster* monster = static_cast<Monster*>(map[dest_pos[r].x][dest_pos[r].y]);
            if (res > 0) {
                deactivate_monster(monster);
                player->gain_exp(1);
            } else if (res == 0 && !monster->is_active()) {
                activate_monster(monster);
            }
        }
    }
    delete dest_pos;
}

void GameEngine::monster_follow() {
    MonsterNode* curNode = head;
    for (; curNode; curNode = curNode->next) {
        curNode->data->follow(*player, map);
    }
}

void GameEngine::monster_act() {
    MonsterNode* curNode = head;
    for (; curNode; curNode = curNode->next) {
        curNode->data->action(*player, map);
    }
}