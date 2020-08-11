#include "drow.h"
#include <cmath>
#include "elf.h"
#include "potion.h"

// Constructor
Drow::Drow(int x, int y, char c = '@', std::string race = "drow", 
           int hp = 125, int atk = 25, int def = 15, int max_hp = 125)
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