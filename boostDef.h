#ifndef BOOST_DEF_H
#define BOOST_DEF_H
#include "potion.h"

class BoostDef: public Potion {
    public:
        virtual void effect() override;
};

#endif
