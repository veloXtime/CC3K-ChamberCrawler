#include "merchant.h"
#include "playerCharacter.h"

// Constructor
Merchant::Merchant(int x, int y, char c = 'M', std::string race = "merchant", 
                   int hp = 30, int atk = 70, int def = 5, int max_hp = 30)
                   : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {slained = false;}

// If any merchant has been slained
bool Merchant::getSlained(){
    return slained;
}

// Upon death of an enemy slained by pc
void Merchant::death(PlayerCharacter &pc){
    slained = true;
    pc.slain();
}

// Override notify
void Merchant::getNotified(PlayerCharacter &pc) {
    if (slained) this->attack(pc);
}
