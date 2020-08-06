#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H
#include "potion.h"

class RestoreHealth: public Potion {
    public:
        virtual void effect() override;
};

#endif
