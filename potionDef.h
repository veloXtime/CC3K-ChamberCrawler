#ifndef DEF_POTION_H
#define DEF_POTION_H
#include "potion.h"

class PotionDef: public Potion 
{
    public:
        // Costructor
        PotionDef(int x, int y, int val, std::shared_ptr<Potion>);
        

        std::pair<int,int> effect() override;
};

#endif
