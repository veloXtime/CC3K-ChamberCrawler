#include "dragon.h"
#include "treasure.h"
// Constructor
Dragon::Dragon(int x, int y, char c, std::string race, 
               int hp, int atk, int def, int max_hp)
               : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

void Dragon::getNotified(PlayerCharacter* pc)
{
    this->attack(*pc);
}

