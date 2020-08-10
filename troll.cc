#include "troll.h"

// Constructor
Troll::Troll(int x, int y, char c = '@', std::string race = "troll", 
             int hp = 125, int atk = 25, int def = 15, int max_hp = 120)
             : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}


// Increase hp of troll by 5
void Troll::incHp(){
    this->setHp(this->getHp() + 5);
}

// Destructor
Troll::~Troll() {}