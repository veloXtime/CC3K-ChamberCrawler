#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include "living.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

// abstract, no instance of PlayerCharacter will be created
class PlayerCharacter: public Living {
    public:
        // Attacking another character
        void attack(Living &c);

        // Attacked by a human
        virtual void attackedBy(Human &human);

        // Attacked by a dwarf
        virtual void attackedBy(Dwarf &dwarf);

        // Attacked by an elf
        virtual void attackedBy(Elf &elf);
        
        // Attacked by an orcs
        virtual void attackedBy(Orcs &orcs);

        // Attacked by a merchant
        virtual void attackedBy(Merchant &merchant);

        // Attacked by a dragon
        virtual void attackedBy(Dragon &dragon);
        
        // Attacked by a halfling
        virtual void attackedBy(Halfling &halfling);
};

#endif
