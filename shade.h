#ifndef SHADE_H
#define SHADE_H
#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Shade: public PlayerCharacter {
    public:
        // Constructor
        Shade(int x, int y, char c = '@', std::string race = "shade", int hp = 125, int atk = 25, int def = 25, int max_hp = 125);
        
        // Destructor
        //virtual ~Shade();
};

#endif
