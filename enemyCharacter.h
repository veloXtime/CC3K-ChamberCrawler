#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H
#include "living.h"

class PlayerCharacter;

// abstract, no instance of EnemyCharacter will be created
class EnemyCharacter: public Living {
    public:
        // Attacking another character
        void attack(PlayerCharacter &pc);

        // Attacked by a PC
        void attackedBy(PlayerCharacter &pc);
   
};

#endif
