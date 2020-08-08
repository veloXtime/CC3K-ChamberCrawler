#include "treasure.h"


Treasure::Treasure(int x, int y, TreasureType val)
:NonLiving(x, y, 'G'), amount{static_cast<int>(val)}
{

}

int Treasure::getAmount() const
{
    return amount;
}


Gold::Gold(int x, int y, TreasureType type)
:Treasure(x, y, type)
{

}


DragonHoard::DragonHoard(int x, int y)
:Treasure(x, y, TreasureType::DRAGON_HOARD)
{
    
}