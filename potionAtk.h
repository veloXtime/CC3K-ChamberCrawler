#ifndef ATK_POTION_H
#define ATK_POTION_H
#include "potion.h"

class PotionAtk: public Potion 
{
    public:
        // Costructor
        PotionAtk(int x, int y, int val, std::shared_ptr<Potion>);

        //void drink(PlayerCharacter*) override;
        std::pair<int,int> effect() override;
};

#endif
