#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include <memory>
#include <utility>
#include "living.h"

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Potion;
class Treasure;


// abstract, no instance of PlayerCharacter will be created
class PlayerCharacter: public Living 
{
    friend class Potion;
    protected:
    
        int HP, Atk, Def;
        int score;
        /* The chain of decorators will return a pair
         * which corresponds to the offset of (ATK, DEF)*/
        std::shared_ptr<Potion> potions;


    public:
        //initialize pointers to the potions component
        PlayerCharacter(int x, int y, char c, 
                        int HP, int Atk, int Def);

        

        void changeHP(int);
        void changeAtk(int);
        void changeDef(int);
        virtual int getHP();
        virtual int getAtk();
        virtual int getDef();

        virtual int getScore();
        
        
        //what notifies PC?
        void notify(GameElement*);

        /* when player decides to drink a potion 
         * adds the potion to the decorator chain */
        void drink(std::shared_ptr<Potion>);

        void pickup(std::shared_ptr<Treasure>);

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
