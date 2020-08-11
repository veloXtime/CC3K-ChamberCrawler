#include "dwarf.h"
#include <math.h>
#include "vampire.h"

// Constructor
Dwarf::Dwarf(int x, int y, char c = 'W', std::string race = "dwarf", 
             int hp = 100, int atk = 20, int def = 30, int max_hp = 100)
             : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Attacked by a vampire
void Dwarf::attackedBy(Vampire &vampire){
    int dmg = ceil(100/(100 + this->getDef()) * vampire.getAtk());
    this->setHp(this->getHp() - dmg);
    vampire.setHp(vampire.getHp() - 5);
}