#ifndef SAHDE_H
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
