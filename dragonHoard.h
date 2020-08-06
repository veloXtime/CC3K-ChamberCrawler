#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H
#include "treasure.h"

class DragonHoard: public Treasure {
    // Notify the dragon associated with this hoard
    void notifyDragon();

    // Determine if the associated dragon is alive
    bool dragonAlive();
    
    public:
        // Costructor
        DragonHoard(int x, int y, char c = 'G', int amount = 6);
};

#endif
