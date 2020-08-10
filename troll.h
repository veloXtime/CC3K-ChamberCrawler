#ifndef TROLL_H
#define TROLL_H
#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Troll: public PlayerCharacter {
    public:
        // Constructor
        Troll(int x, int y, char c = '@', std::string race = "troll", int hp = 125, int atk = 25, int def = 15, int max_hp = 120);

        // Increase hp of troll by 5
        void incHp();
        
        // Destructor
        virtual ~Troll();
};

#endif
