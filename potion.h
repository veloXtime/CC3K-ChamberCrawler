#ifndef POTION_H
#define POTION_H
#include "nonliving.h"

// abstract, no instance of Potion will be created
class Potion: public NonLiving {
    public:
        virtual void effect();
};

#endif
