#include "potion.h"
#include "display.h"


Potion::Potion(int x, int y, int val) 
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


    PotionHP* temp = dynamic_cast<PotionHP*>(this);
    if (temp){
        if (val > 0) gameDisplay.newAction("PC uses RH. ");
        else gameDisplay.newAction("PC uses PH. ");
    }
    else{
        PotionAtk* temp = dynamic_cast<PotionAtk*>(this);
        if (temp){
            if (val > 0) gameDisplay.newAction("PC uses BA. ");
            else gameDisplay.newAction("PC uses WA. ");
        } 
        else{
            PotionDef* temp = dynamic_cast<PotionDef*>(this);
            if (temp){
                if (val > 0) gameDisplay.newAction("PC uses BD. ");
                else gameDisplay.newAction("PC uses WD. ");
            }
        }
    }
    
}

void Potion::getNotified(PlayerCharacter& p)
{
    
}

/* HP potion */
PotionHP::PotionHP(int x, int y, int val)
:Potion(x,y,val)
{
}

std::pair<int, int> PotionHP::effect()
{
    //error
}

void PotionHP::drink(PlayerCharacter* p)
{
    p->setHp(p->getHp() + val);
}
/* HP potion */

/* Atk Potion */
PotionAtk::PotionAtk(int x, int y, int val)
:Potion(x,y,val)
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
PotionDef::PotionDef(int x, int y, int val)
:Potion(x,y,val)
{
}

std::pair<int, int> PotionDef::effect()
{
    auto v = next->effect();
    v.second += val;
    return v;
}
