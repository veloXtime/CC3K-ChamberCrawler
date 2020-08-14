#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include <memory>
#include <utility>
#include "living.h"

class EnemyCharacter;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Potion;
class Treasure;


class PlayerCharacter : public Living 
{
    friend class Treasure;

    protected:
    
        int score;
        /* The chain of decorators will return a pair
         * which corresponds to the offset of (ATK, DEF)*/
        std::shared_ptr<Potion> potions;


    public:
        //initialize pointers to the potions component
        PlayerCharacter(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp);

        
        virtual int getAtk() const override;
        virtual int getDef() const override;
        virtual int getScore();
        void setScore(int v);
        
        // Notify a game element
        void notify(std::shared_ptr<GameElement> ge);
        virtual void getNotified(PlayerCharacter & pc) override;	// pure virtual must be implemented

        /* when player decides to drink a potion 
         * adds the potion to the decorator chain */
        void drink(std::shared_ptr<Potion>);

        void pickup(std::shared_ptr<Treasure>);

        // Attacking another character
        void attack(EnemyCharacter &c);

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

        //Slains an enemy
        virtual void slain(char race);
        
};

#endif
