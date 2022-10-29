#include "EmptyLand.h"

//write your codes here
/**
EmptyLand(int x, int y)
The constructor of the class EmptyLand. Input argument x and y specifies the coordinate where the target EmptyLand unit locates. The coordinate should be assigned to the protected member variable x and y defined in the class MapUnit.
~EmptyLand()
You should also implement the destructor properly.
bool is_blocked() const override
Override the pure virtual function virtual bool is_blocked() const = 0 declared in the class MapUnit. This function should always return false since the EmptyLand unit is not blocked.
string get_display_str() const override
Override the pure virtual function virtual string get_display_str() const = 0 declared in the class MapUnit. This function should always return the constant SYM_EMPTY defined in MapUnit.h.
 */

// should be okay
EmptyLand::EmptyLand(int x, int y)
    : Terrain(x, y) { }

EmptyLand::~EmptyLand() {}

bool EmptyLand::is_blocked() const {
    return false;
}

string EmptyLand::get_display_str() const {
    return SYM_EMPTY;
}