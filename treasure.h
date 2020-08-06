#ifndef TREASURE_H
#define TREASURE_H
#include "nonliving.h"

// abstract, no instance of Treasure will be created
class Treasure: public NonLiving {
    int amount;

    public:
        int getAmount() const;
};

#endif
