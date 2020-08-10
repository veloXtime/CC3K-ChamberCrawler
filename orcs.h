#ifndef ORCS_H
#define ORCS_H
#include "enemyCharacter.h"

class Orcs: public EnemyCharacter {
    public:
        // Constructor
        Orcs(int x, int y, char c = 'O', std::string race = "orcs", int hp = 180, int atk = 30, int def = 25, int max_hp = 180);

        // Destructor
        virtual ~Orcs();
};

#endif
