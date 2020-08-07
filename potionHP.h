#ifndef HP_POTION_H
#define HP_POTION_H
#include "potion.h"

class PotionHP: public Potion 
{
    
    public:
        // Costructor
        PotionHP(int x, int y, int val, std::shared_ptr<Potion>);

        void drink(PlayerCharacter*) override;
        std::pair<int,int> effect() override;
};

#endif
