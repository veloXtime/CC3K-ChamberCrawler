#include "drow.h"
#include "math.h"
#include "elf.h"

// Constructor
Drow::Drow(int x, int y, char c = '@', std::string race = "drow", 
           int hp = 125, int atk = 25, int def = 15, int max_hp = 125)
           : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} {}

// Attacked by an elf
void Drow::attackedBy(Elf &elf) {
    int dmg = ceil(100/(100 + this->getDef()) * elf.getAtk());
    this->setHp(this->getHp() - dmg);
}
