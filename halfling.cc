#include "halfling.h"

// Constructor
Halfling::Halfling(int x, int y, char c = 'L', std::string race = "halfling", 
                   int hp = 100, int atk = 15, int def = 20, int max_hp = 100)
                   : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Halfling::~Halfling() {}

// Get notified by a pc
void Halfling::getNotified(PlayerCharacter & pc){
    this->attack(pc);
}
