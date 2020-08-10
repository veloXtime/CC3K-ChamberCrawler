#ifndef GOBLIN_H
#define GOBLIN_H
#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Goblin: public PlayerCharacter {
    public:
        // Constructor
        Goblin(int x, int y, char c = '@', std::string race = "goblin", int hp = 110, int atk = 15, int def = 20, int max_hp = 125);

        // Attacked by an orcs
        virtual void attackedBy(Orcs &orcs) override;

        // Override slain
        virtual void slain() override;

        // Destructor
        ~Goblin();
};

#endif
