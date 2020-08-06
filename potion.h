#ifndef POTION_H
#define POTION_H
#include "nonliving.h"

class Potion: public NonLiving {
    public:
        virtual void effect();
};

#endif
