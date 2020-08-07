#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include <memory>
#include "potion.h"
#include "living.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;


// abstract, no instance of PlayerCharacter will be created
class PlayerCharacter: public Living 
{
    protected:
        int HP, Atk, Def;

        std::unique_ptr<Potion> potions;

        void changeHP(int);
        void changeAtk(int);
        void changeDef(int);
    public:
        //initialize pointers to the potions component
        PlayerCharacter();
        PlayerCharacter(int, int, int); //the three stats?

        /* The chain of decorators will return aa 3-tuple
         * which corresponds to the offset of (HP, ATK, DEF)*/
        int getHP();
        int getAtk();
        int getDef();
        
        
        //what notifies PC?
        void notify(GameElement*);

        /* when player decides to drink a potion 
         * adds the potion to the decorator chain*/
        void drink(std::unique_ptr<Potion>&);


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
