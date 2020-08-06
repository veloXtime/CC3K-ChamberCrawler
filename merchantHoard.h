#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H
#include "treasure.h"

class MerchantHoard: public Treasure {
    public:
        // Costructor
        MerchantHoard(int x, int y, char c = 'G', int amount = 4);
};

#endif
