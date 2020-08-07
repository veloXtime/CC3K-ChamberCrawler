#include "playerCharacter.h"


PlayerCharacter::PlayerCharacter
(int x, int y, char c, int HP, int Atk, int Def)
: Living(x, y, c), HP{HP}, Atk{Atk}, Def{Def}, 
potions{std::make_shared<Potion>()}
{

}

int PlayerCharacter::getHP()
{
    return HP;
}

int PlayerCharacter::getAtk()
{
    return Atk + potions->effect().first;
}

int PlayerCharacter::getDef()
{
    return Def + potions->effect().second;
}

void PlayerCharacter::drink(std::shared_ptr<Potion> p)
{
    p->drink(this); //modify this accordingly
}



