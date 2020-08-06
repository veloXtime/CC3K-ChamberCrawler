#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H
#include "potion.h"

class PoisonHealth: public Potion {
    public:
        virtual void effect() override;
};

#endif
