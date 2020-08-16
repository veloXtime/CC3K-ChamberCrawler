#include "shade.h"
#include "debug.h"
// Constructor
Shade::Shade(int x, int y, char c, std::string race,
             int hp, int atk, int def, int max_hp)
             : PlayerCharacter{x, y, c, race, hp, atk, def, max_hp} 
             {
                 #ifdef DEBUG
                 this->def = 1000;
                 #endif
             }

int Shade::getScore()
{
    return 1.5 * score;
}
