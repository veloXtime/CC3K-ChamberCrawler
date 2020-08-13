#include "vampire.h"

// Constructor
Vampire::Vampire(int x, int y, char c, std::string race, 
                 int hp, int atk, int def, int max_hp)
                 : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}

// Destructor
Vampire::~Vampire() {}
