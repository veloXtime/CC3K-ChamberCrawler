#include "potion.h"


Potion::Potion(int x, int y, int val, std::shared_ptr<Potion> p) 
: NonLiving(x, y, 'P'), val{val}, next{nullptr}
{

}

std::pair<int, int> Potion::effect()
{
    return std::make_pair<int,int>(0, 0);
}

void Potion::drink(PlayerCharacter* p)
{
    next = p->potions;
    p->potions = std::shared_ptr<Potion>(this);
}


/* HP potion */
PotionHP::PotionHP(int x, int y, int val, std::shared_ptr<Potion> p)
:Potion(x,y,val, nullptr)
{
}

std::pair<int, int> PotionHP::effect()
{
    //error
}

void PotionHP::drink(PlayerCharacter* p)
{
    p->changeHP(p->getHP() + val);
}
/* HP potion */

/* Atk Potion */
PotionAtk::PotionAtk(int x, int y, int val, std::shared_ptr<Potion> p)
:Potion(x,y,val, nullptr)
{
}

std::pair<int, int> PotionAtk::effect()
{
    auto v = next->effect();
    v.first += val;
    return v;
}
/* Atk Potion */

/* Def Potion */
PotionDef::PotionDef(int x, int y, int val, std::shared_ptr<Potion> p)
:Potion(x,y,val, nullptr)
{
}

std::pair<int, int> PotionDef::effect()
{
    auto v = next->effect();
    v.second += val;
    return v;
}
