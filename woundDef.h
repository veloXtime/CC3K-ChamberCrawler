#ifndef WOUND_DEF_H
#define WOUND_DEF_H
#include "potion.h"

class WoundDef: public Potion {
    public:
        // Costructor
        WoundDef(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
