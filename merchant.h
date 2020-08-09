#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyCharacter.h"

class Merchant: public EnemyCharacter {
    bool slained;

    public:
        // Constructor
        Merchant(int x, int y, char c = 'M', std::string race = "merchant", int hp = 30, int atk = 70, int def = 5, int max_hp = 30, bool slained = false);

        // If any merchant has been slained
        bool getSlained();

        // Upon death of an enemy slained by pc
        virtual void death(PlayerCharacter &pc) override;
};

#endif
