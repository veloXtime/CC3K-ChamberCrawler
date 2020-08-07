#ifndef ATK_POTION_H
#define ATK_POTION_H
#include "potion.h"

class PotionAtk: public Potion 
{
    public:
        // Costructor
        PotionAtk(int x, int y, int val, std::unique_ptr<Potion>, char c = 'P');

        virtual int effect() override;
};

#endif
