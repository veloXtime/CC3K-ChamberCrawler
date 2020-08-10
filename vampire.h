#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "playerCharacter.h"
#include <limits>

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Vampire: public PlayerCharacter {
    public:
        // Constructor
        Vampire(int x, int y, char c = '@', std::string race = "vampire", 
                int hp = 50, int atk = 25, int def = 25, int max_hp = std::numeric_limits<int>::max());
        
        // Destructor
        ~Vampire();
};

#endif
