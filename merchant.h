#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyCharacter.h"

class Merchant: public EnemyCharacter {
    public:
        // Constructor
        Merchant(int x, int y, char c = 'M', std::string race = "merchant", int hp = 30, int atk = 70, int def = 5, int max_hp = 30);
};

#endif
