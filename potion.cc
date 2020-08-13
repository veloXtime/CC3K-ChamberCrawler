#include "potion.h"
#include "display.h"


Potion::Potion(int x, int y, int val) 
: NonLiving(x, y, 'P'), val{val}, next{nullptr}
{}

Potion::Potion()
: NonLiving(-1, -1, 'P'), val{0}, next{nullptr}
{}

std::pair<int, int> Potion::effect()
{
    return std::make_pair<int,int>(0, 0);
}

// void Potion::drink(std::shared_ptr<PlayerCharacter> p)
// {
//     //next = p->potions;
//     p->drink()
//     gameDisplay.action(ACTION::DrinkP, this);
// }

void Potion::getNotified(PlayerCharacter& p)
{
    gameDisplay.action(ACTION::SeePotion);
}

std::string Potion::getType()
{
    return type;
}

/* HP potion */
PotionHP::PotionHP(int x, int y, int val)
:Potion(x,y,val)
{
    if(val > 0)
        type = "RH";
    else
        type = "PH";
}

std::pair<int, int> PotionHP::effect()
{
    return std::make_pair<int, int>(0, 0);
}

// void PotionHP::drink(PlayerCharacter* pc)
// {
//     if(pc->getRace() == "drow")
//         val*=1.5;
//     pc->setHp(pc->getHp() + val);

//     gameDisplay.action(ACTION::DrinkP, this);
// }
/* HP potion */

/* Atk Potion */
PotionAtk::PotionAtk(int x, int y, int val)
:Potion(x,y,val)
{
    if(val > 0)
        type = "BA";
    else
        type = "WA";
}

std::pair<int, int> PotionAtk::effect()
{
    auto v = next->effect();
    v.first += val;
    return v;
}
/* Atk Potion */

/* Def Potion */
PotionDef::PotionDef(int x, int y, int val)
:Potion(x,y,val)
{
    if(val > 0)
        type = "BD";
    else
        type = "WD";
}

std::pair<int, int> PotionDef::effect()
{
    auto v = next->effect();
    v.second += val;
    return v;
}
