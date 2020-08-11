#ifndef HALFLING_H
#define HALFLING_H
#include "enemyCharacter.h"

class Halfling: public EnemyCharacter {
    public:
        // Constructor
        Halfling(int x, int y, char c = 'L', std::string race = "halfling", int hp = 100, int atk = 15, int def = 20, int max_hp = 100);

        // Destructor
        virtual ~Halfling();

        // Get notified by a pc
        virtual void getNotified(PlayerCharacter & pc) override;
};

#endif
