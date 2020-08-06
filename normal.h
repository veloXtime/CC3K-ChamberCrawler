#ifndef NORMAL_H
#define NORMAL_H
#include "treasure.h"

class Normal: public Treasure {
    public:
        // Costructor
        Normal(int x, int y, char c = 'G', int amount = 2);
};

#endif
