#ifndef WOUND_DEF_H
#define WOUND_DEF_H
#include "potion.h"

class WoundDef: public Potion {
    public:
        virtual void effect() override;
};

#endif
