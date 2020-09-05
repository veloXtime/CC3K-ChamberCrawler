#include "troll.h"

// Constructor
Troll::Troll(int x, int y, char c, std::string race, 
             int hp, int atk, int def, int max_hp)
             : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}


// Increase hp of troll by 5
void Troll::incHp(){
    this->setHp(this->getHp() + 5);
}

// Destructor
Troll::~Troll() {}
