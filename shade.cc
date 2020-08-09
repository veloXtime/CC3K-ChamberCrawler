#include "shade.h"

// Constructor
Shade::Shade(int x, int y, char c = '@', std::string race = "shade",
             int hp = 125, int atk = 25, int def = 25, int max_hp = 125)
             : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}
