#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H
#include "living.h"

class PlayerCharacter;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

// abstract, no instance of EnemyCharacter will be created
class EnemyCharacter: public Living {
    public:
        // Constructor
        EnemyCharacter(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp);

        // Attacking another character
        void attack(PlayerCharacter &pc);

        // Attacked by a shade
        void attackedBy(Shade &shade);

        // Attacked by a drow
        void attackedBy(Drow &drow);

        // Attacked by a vampire
        virtual void attackedBy(Vampire &vampire);

        // Attacked by a troll
        void attackedBy(Troll &troll);

        // Attacked by a goblin
        void attackedBy(Goblin &goblin);

        // Upon death of an enemy slained by pc
        virtual void death(PlayerCharacter &pc);
   
};

#endif
