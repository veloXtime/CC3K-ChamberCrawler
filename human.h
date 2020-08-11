#ifndef HUMAN_H
#define HUMAN_H
#include "enemyCharacter.h"

class Human: public EnemyCharacter {
    public:
        // Constructor
        Human(int x, int y, char c = 'H', std::string race = "human", int hp = 140, int atk = 20, int def = 20, int max_hp = 140);

        // Destructor
        virtual ~Human();

        // Upon death of a human slained by pc
        virtual void death(PlayerCharacter &pc) override;
};

#endif
