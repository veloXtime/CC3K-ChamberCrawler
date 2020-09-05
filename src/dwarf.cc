#include "dwarf.h"
#include <math.h>
#include "vampire.h"
#include "display.h"
// Constructor
Dwarf::Dwarf(int x, int y, char c, std::string race, 
             int hp, int atk, int def, int max_hp)
             : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Attacked by a vampire
void Dwarf::attackedBy(Vampire &vampire){
    int dmg = ceil(100.0/(100 + this->getDef()) * vampire.getAtk());
    this->setHp(this->getHp() - dmg);
    vampire.setHp(vampire.getHp() - 5);

    gameDisplay.action(ACTION::AtkEnemy, dmg, &vampire , this);
}
