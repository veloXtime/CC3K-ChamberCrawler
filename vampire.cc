#include "vampire.h"

// Constructor
Vampire::Vampire(int x, int y, char c = '@', std::string race = "vampire", 
                 int hp = 50, int atk = 25, int def = 25, int max_hp = std::numeric_limits<int>::max())
                 : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}

// Destructor
Vampire::~Vampire() {}
