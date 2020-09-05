#include "drow.h"
#include <cmath>
#include "elf.h"
#include "potion.h"

// Constructor
Drow::Drow(int x, int y, char c, std::string race, 
           int hp, int atk, int def, int max_hp)
           : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}

// Attacked by an elf
void Drow::attackedBy(Elf &elf) {
    int dmg = ceil(100/(100 + this->getDef()) * elf.getAtk());
    this->setHp(this->getHp() - dmg);
}

int Drow::getAtk() const
{
    return atk + 1.5 * potions->effect().first;
}

int Drow::getDef() const
{
    return def + 1.5 * potions->effect().second;
}
