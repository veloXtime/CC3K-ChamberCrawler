#include "elf.h"

// Constructor
Elf::Elf(int x, int y, char c = 'E', std::string race = "elf", 
         int hp = 140, int atk = 30, int def = 10, int max_hp = 140)
         : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Elf::~Elf() {}
