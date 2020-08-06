#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H
#include "potion.h"

class PoisonHealth: public Potion {
    public:
        // Costructor
        PoisonHealth(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
