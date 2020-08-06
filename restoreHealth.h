#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H
#include "potion.h"

class RestoreHealth: public Potion {
    public:
        // Costructor
        RestoreHealth(int x, int y, char c = 'P');

        virtual void effect() override;
};

#endif
