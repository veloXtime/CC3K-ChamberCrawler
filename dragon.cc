#include "dragon.h"

// Constructor
Dragon::Dragon(int x, int y, char c, std::string race, 
               int hp, int atk, int def, int max_hp)
               : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Get notified by a dragon hoard
void Dragon::DGetNotified(DragonHoard & dh){
    
}

