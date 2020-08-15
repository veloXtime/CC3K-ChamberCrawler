#include <cmath>
#include "treasure.h"
#include "merchant.h"
#include "playerCharacter.h"
#include "display.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "board.h"

bool Merchant::hostile = false;
// Constructor
Merchant::Merchant(int x, int y, char c, std::string race, 
                   int hp, int atk, int def, int max_hp)
                   : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) 
                   {Merchant::hostile = false;}

// If any merchant has been attacked
bool Merchant::getHostile(){
    return Merchant::hostile;
}

// Upon death of a merchant slained by pc
void Merchant::death(PlayerCharacter &pc){
    pc.slain('M');

    std::string s = "Some gold is left on the floor. ";
    gameDisplay.newAction(s, false);
}

// Override notify
void Merchant::getNotified(PlayerCharacter &pc) {
    if (Merchant::hostile) this->attack(pc);
}

// Destructor
Merchant::~Merchant() {}

inline void gotAttaked(int dmg, PlayerCharacter* pc, EnemyCharacter* enemy)
{
    gameDisplay.action(ACTION::AtkEnemy, dmg, pc , enemy);
    gameDisplay.newAction("All merchants are now hostile to PC. ", false);
}

// Attacked by a shade
void Merchant::attackedBy(Shade &shade){
    hostile = true;
    int dmg = ceil(100.0/(100 + this->getDef()) * shade.getAtk());
    this->setHp(this->getHp() - dmg);

    gotAttaked(dmg, &shade, this);
}

// Attacked by a drow
void Merchant::attackedBy(Drow &drow){
    Merchant::hostile = true;
    int dmg = ceil(100.0/(100 + this->getDef()) * drow.getAtk());
    this->setHp(this->getHp() - dmg);

    gotAttaked(dmg, &drow, this);
}

// Attacked by a vampire
void Merchant::attackedBy(Vampire &vampire){
    hostile = true;
    int dmg = ceil(100.0/(100 + this->getDef()) * vampire.getAtk());
    this->setHp(this->getHp() - dmg);
    vampire.setHp(vampire.getHp() + 5);

    gotAttaked(dmg, &vampire, this);
}

// Attacked by a troll
void Merchant::attackedBy(Troll &troll){
    Merchant::hostile = true;
    int dmg = ceil(100.0/(100 + this->getDef()) * troll.getAtk());
    this->setHp(this->getHp() - dmg);

    gotAttaked(dmg, &troll, this);

// Attacked by a goblin
void Merchant::attackedBy(Goblin &goblin)
{
    Merchant::hostile = true;
    int dmg = ceil(100.0/(100 + this->getDef()) * goblin.getAtk());
    this->setHp(this->getHp() - dmg);

    gotAttaked(dmg, &goblin, this);

