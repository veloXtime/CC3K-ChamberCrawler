#ifndef HP_POTION_H
#define HP_POTION_H
#include "potion.h"

class PotionHP: public Potion 
{
    public:
        // Costructor
        PotionHP(int x, int y, int val, std::unique_ptr<Potion>, char c = 'P');

        virtual int effect() override;
};

#endif
