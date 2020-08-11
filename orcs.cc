#include "orcs.h"

// Constructor
Orcs::Orcs(int x, int y, char c = 'O', std::string race = "orcs", 
           int hp = 180, int atk = 30, int def = 25, int max_hp = 180)
           : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Orcs::~Orcs() {}
