#ifndef TREASURE_H
#define TREASURE_H
#include "nonliving.h"

class Treasure: public NonLiving {
    int amount;

    public:
        int getAmount() const;
};

#endif
