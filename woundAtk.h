#ifndef WOUND_ATK_H
#define WOUND_ATK_H
#include "potion.h"

class WoundAtk: public Potion {
    public:
        // Costructor
        WoundAtk(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
