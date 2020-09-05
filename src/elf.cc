#include "elf.h"

// Constructor
Elf::Elf(int x, int y, char c, std::string race, 
         int hp, int atk, int def, int max_hp)
         : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Elf::~Elf() {}
