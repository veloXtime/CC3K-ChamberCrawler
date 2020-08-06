#ifndef BOOST_ATK_H
#define BOOST_ATK_H
#include "potion.h"

class BoostAtk: public Potion {
    public:
        // Costructor
        BoostAtk(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
