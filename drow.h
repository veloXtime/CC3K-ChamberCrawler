#ifndef DROW_H
#define DROW_H
#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Drow: public PlayerCharacter {
    public:
        // Constructor
        Drow(int x, int y, char c = '@', std::string race = "drow", int hp = 125, int atk = 25, int def = 15, int max_hp = 125);

        // Attacked by an elf
        void attackedBy(Elf &elf) override;
        int getAtk() const override;
        int getDef() const override;

        
        
};

#endif
