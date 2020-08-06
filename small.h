#ifndef SMALL_H
#define SMALL_H
#include "treasure.h"

class Small: public Treasure {
    public:
        // Costructor
        Small(int x, int y, char c = 'G', int amount = 1);
};

#endif
