#include "human.h"

// Constructor
Human::Human(int x, int y, char c = 'H', std::string race = "human", 
             int hp = 140, int atk = 20, int def = 20, int max_hp = 140)
             : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}
