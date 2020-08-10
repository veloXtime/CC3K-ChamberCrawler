#include "goblin.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "orcs.h"

// Constructor
Goblin::Goblin(int x, int y, char c = '@', std::string race = "goblin", 
               int hp = 110, int atk = 15, int def = 20, int max_hp = 125)
               : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}

// Attacked by an orcs
void Goblin::attackedBy(Orcs &orcs) {
    int dmg = ceil(100/(100 + this->getDef()) * orcs.getAtk() * 1.5);
    this->setHp(this->getHp() - dmg);
}

// Override slain
void Goblin::slain() {
    srand (time(NULL));
    int gold = rand() % 2 + 1;
    this->setScore(score + gold + 5);
}

// Destructor
Goblin::~Goblin() {}