#include "treasure.h"
#include "display.h"
#include "dragon.h"
Treasure::Treasure(int x, int y, TreasureType val)
:NonLiving(x, y, 'G'), amount{static_cast<int> (val)}
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


DragonHoard::DragonHoard(int x, int y, std::shared_ptr<Dragon> dragon)
:Treasure(x, y, TreasureType::DRAGON_HOARD), doragon{dragon}
{
    
}

void DragonHoard::setDragon(std::shared_ptr<Dragon> dragon)
{
	doragon = dragon;
}

int DragonHoard::getAmount() const
{
    if(doragon->getHp() == 0)
        return amount;
    return 0;
}

void DragonHoard::getNotified(PlayerCharacter& pc)
{
    doragon->getNotified(&pc);
}
