#ifndef TREASURE_H
#define TREASURE_H
#include "nonliving.h"

class PlayerCharacter;
class Dragon;

enum class TreasureType:int {SMALL_PILE = 1, NORMAL_PILE = 2, MERCHANT = 4, DRAGON_HOARD = 6 };

//abstract
class Treasure: public NonLiving {
    int amount;

    public:
        Treasure(int, int, TreasureType);
        int getAmount() const;

        //get called when PC is neary by
        void notify(PlayerCharacter*);
};


class Gold : public Treasure
{
    public:
        Gold(int, int, TreasureType);
        
};


class DragonHoard : public Treasure
{
    public:
        DragonHoard(int, int);

        //when dragon is slain
        void notify(Dragon*);
};
#endif
