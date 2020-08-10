#ifndef DRAGON_H
#define DRAGON_H
#include "enemyCharacter.h"

class DragonHoard;

class Dragon: public EnemyCharacter {
    public:
        // Constructor
        Dragon(int x, int y, char c = 'D', std::string race = "dragon", int hp = 150, int atk = 20, int def = 20, int max_hp = 150);

        // Get notified by a dragon hoard
        void DGetNotified(DragonHoard & dh);

        // Destructor
        virtual ~Dragon();
};

#endif
