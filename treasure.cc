#include "treasure.h"
#include "display.h"

Treasure::Treasure(int x, int y, TreasureType val)
:NonLiving(x, y, 'G'), amount{static_cast<int> (val)}}
{
}

int Treasure::getAmount() const
{
    return amount;
}

void Treasure::getNotified(PlayerCharacter& pc)
{
    gameDisplay.action(ACTION::SeeGold);
}

Gold::Gold(int x, int y, TreasureType type)
:Treasure(x, y, type)
{

}


DragonHoard::DragonHoard(int x, int y)
:Treasure(x, y, TreasureType::DRAGON_HOARD)
{
    
}
