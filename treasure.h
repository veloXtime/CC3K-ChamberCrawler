#ifndef TREASURE_H
#define TREASURE_H
#include "nonliving.h"
#include <memory>

class PlayerCharacter;
class Dragon;

enum class TreasureType:int {SMALL_PILE = 1, NORMAL_PILE = 2, MERCHANT = 4, DRAGON_HOARD = 6 };

//abstract
class Treasure: public NonLiving 
{
    protected:
        int amount;

    public:
        Treasure(int, int, TreasureType);
        virtual int getAmount() const;

        //get called when PC is neary by
        void getNotified(PlayerCharacter&) override;
};


class Gold : public Treasure
{
    public:
        Gold(int, int, TreasureType);
        
};


class DragonHoard : public Treasure
{
    std::shared_ptr<Dragon> doragon;
    public:
        DragonHoard(int, int, std::shared_ptr<Dragon>);

        int getAmount() const override;
        //when dragon is slain
        void notify(Dragon*);
};
#endif
