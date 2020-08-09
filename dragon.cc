#include "dragon.h"

// Constructor
Dragon::Dragon(int x, int y, char c = 'D', std::string race = "dragon", 
               int hp = 150, int atk = 20, int def = 20, int max_hp = 150)
               : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}
