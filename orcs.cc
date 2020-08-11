#include "orcs.h"

// Constructor
Orcs::Orcs(int x, int y, char c, std::string race, 
           int hp, int atk, int def, int max_hp)
           : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Orcs::~Orcs() {}
