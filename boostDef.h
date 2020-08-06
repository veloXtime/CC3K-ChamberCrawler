#ifndef BOOST_DEF_H
#define BOOST_DEF_H
#include "potion.h"

class BoostDef: public Potion {
    public:
        // Costructor
        BoostDef(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
