#ifndef DEF_POTION_H
#define DEF_POTION_H
#include "potion.h"

class PotionDef: public Potion 
{
    public:
        // Costructor
        PotionDef(int x, int y, int val, std::unique_ptr<Potion>, char c = 'P');
        

        virtual int effect() override;
};

#endif
