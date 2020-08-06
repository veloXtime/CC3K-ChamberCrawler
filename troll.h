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
        // Attacked by a human
        virtual void attackedBy(Human &human) override;

        // Attacked by a dwarf
        virtual void attackedBy(Dwarf &dwarf) override;

        // Attacked by an elf
        virtual void attackedBy(Elf &elf) override;
        
        // Attacked by an orcs
        virtual void attackedBy(Orcs &orcs) override;

        // Attacked by a merchant
        virtual void attackedBy(Merchant &merchant) override;

        // Attacked by a dragon
        virtual void attackedBy(Dragon &dragon) override;
        
        // Attacked by a halfling
        virtual void attackedBy(Halfling &halfling) override;
        
};

#endif
