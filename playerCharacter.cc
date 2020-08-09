#include "playerCharacter.h"
#include "potion.h"
#include "treasure.h"
#include <math.h>
#include <cstdlib>
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

PlayerCharacter::PlayerCharacter
(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp)
: Living(x, y, c, race, hp, atk, def, max_hp), 
  score{0}, potions{std::make_shared<Potion>()} {}

int PlayerCharacter::getAtk() const
{
    return atk + potions->effect().first;
}

int PlayerCharacter::getDef() const
{
    return def + potions->effect().second;
}

int PlayerCharacter::getScore()
{
    return score;
}

int PlayerCharacter::setScore(int v){
    score = v;
}

void PlayerCharacter::drink(std::shared_ptr<Potion> p)
{
    p->drink(this); //modify this accordingly
}

void PlayerCharacter::pickup(std::shared_ptr<Treasure> p)
{
    score += p->getAmount();
    //should it also be responsible for removing p from the board?
}

//what notifies PC?
void PlayerCharacter::notify(GameElement*)
{

}

// Attacking another character
void PlayerCharacter::attack(EnemyCharacter &c)
{
    c.attackedBy(*this);
}

// Attacked by a human
void PlayerCharacter::attackedBy(Human &human)
{
    int dmg = ceil(100/(100 + this->getDef()) * human.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a dwarf
void PlayerCharacter::attackedBy(Dwarf &dwarf)
{
    int dmg = ceil(100/(100 + this->getDef()) * dwarf.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by an elf
void PlayerCharacter::attackedBy(Elf &elf)
{
    int dmg = ceil(100/(100 + this->getDef()) * elf.getAtk());
    this->setHp(this->getHp() - 2*dmg);
}

// Attacked by an orcs
void PlayerCharacter::attackedBy(Orcs &orcs)
{
    int dmg = ceil(100/(100 + this->getDef()) * orcs.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a merchant
void PlayerCharacter::attackedBy(Merchant &merchant)
{
    int dmg = ceil(100/(100 + this->getDef()) * merchant.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a dragon
void PlayerCharacter::attackedBy(Dragon &dragon)
{
    int dmg = ceil(100/(100 + this->getDef()) * dragon.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a halfling
void PlayerCharacter::attackedBy(Halfling &halfling)
{
    int dmg = ceil(100/(100 + this->getDef()) * halfling.getAtk());
    this->setHp(this->getHp() - dmg);
}

void PlayerCharacter::slain(){
    int gold = rand() % 2 + 1;
    this->setScore(score + gold);
}