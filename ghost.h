#ifndef GHOST_H
#define GHOST_H
#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Ghost: public PlayerCharacter {
    public:
        // Constructor
        Ghost(int x, int y, char c = '@', std::string race = "ghost", int hp = 80, int atk = 30, int def = 15, int max_hp = 80);

        // Destructor
        virtual ~Ghost();
};

#endif
