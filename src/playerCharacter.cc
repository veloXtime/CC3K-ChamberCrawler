#include "playerCharacter.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "potion.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "ghost.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "display.h"
#include "potion.h"
#include "treasure.h"

PlayerCharacter::PlayerCharacter
(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp)
: Living(x, y, c, race, hp, atk, def, max_hp), 
  score{0}, potions{std::make_shared<Potion>()} {}

int PlayerCharacter::getAtk() const
{
    return std::max(0, atk + potions->effect().first);
}

int PlayerCharacter::getDef() const
{
    return std::max(0, def + potions->effect().second);
}

int PlayerCharacter::getScore()
{
    return score;
}

void PlayerCharacter::setScore(int v)
{
    score = v;
}

void PlayerCharacter::drink(std::shared_ptr<Potion> p)
{
    if(p->type[1] == 'H')
    {
        if(getRace() == "drow")
            p->val*=1.5;
        setHp(getHp() + p->val);
    }
    //else
    {
        p->next = potions;
        potions = p;
    }
    gameDisplay.action(ACTION::DrinkP, p.get());
        
}

bool PlayerCharacter::pickup(std::shared_ptr<Treasure> p)
{
    if(p->getAmount() == 0)
    {
        gameDisplay.newAction("Dragon is still alive, you cannot pick up the Dragon Hoard. ", false);
        return false;
    }
    score += p->getAmount();
    //should it also be responsible for removing p from the board?
    
    gameDisplay.action(ACTION::PickG, p->getAmount());
    return true;

}

// Notify a game element
void PlayerCharacter::notify(std::shared_ptr<GameElement> ge)
{
    ge->getNotified(*this);
}

void PlayerCharacter::getNotified(PlayerCharacter & pc) {}
// Attacking another character
void PlayerCharacter::attack(EnemyCharacter &c)
{
    if (c.getChar() == 'L'){
        int success = rand() % 2;
        if (success == 1){
            if (this->getRace() == "shade")
            {
                Shade & s = static_cast<Shade &> (*this);
                c.attackedBy(s);
            }
            else if (this->getRace() == "drow")
            {
                Drow & d = static_cast<Drow &> (*this);
                c.attackedBy(d);
            }
            else if (this->getRace() == "vampire")
            {
                Vampire & v = static_cast<Vampire &> (*this);
                c.attackedBy(v);
            }
            else if (this->getRace() == "troll")
            {
                Troll & t = static_cast<Troll &> (*this);
                c.attackedBy(t);
            }
            else if (this->getRace() == "goblin")
            {
                Goblin & g = static_cast<Goblin &> (*this);
                c.attackedBy(g);
            }
            else if (this->getRace() == "ghost")
            {
                Ghost & h = static_cast<Ghost &> (*this);
                c.attackedBy(h);
            }
        }
        else{
            std::string s = "PC misses attack. ";
            gameDisplay.newAction(s, false);
        }
    }
    else{
        if (this->getRace() == "shade")
        {
            Shade & s = static_cast<Shade &> (*this);
            c.attackedBy(s);
        }
        else if (this->getRace() == "drow")
        {
            Drow & d = static_cast<Drow &> (*this);
            c.attackedBy(d);
        }
        else if (this->getRace() == "vampire")
        {
            Vampire & v = static_cast<Vampire &> (*this);
            c.attackedBy(v);
        }
        else if (this->getRace() == "troll")
        {
            Troll & t = static_cast<Troll &> (*this);
            c.attackedBy(t);
        }
        else if (this->getRace() == "goblin")
        {
            Goblin & g = static_cast<Goblin &> (*this);
            c.attackedBy(g);
        }
        else if (this->getRace() == "ghost")
        {
            Ghost & h = static_cast<Ghost &> (*this);
            c.attackedBy(h);
        }
    }
}

// Attacked by a human
void PlayerCharacter::attackedBy(Human &human)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * human.getAtk());
    this->setHp(this->getHp() - dmg);

    gameDisplay.action(ACTION::GotAtk, dmg, &human, this);

    // std::string sdmg = std::to_string(dmg);
    // std::string s = "H deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by a dwarf
void PlayerCharacter::attackedBy(Dwarf &dwarf)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * dwarf.getAtk());
    this->setHp(this->getHp() - dmg);
    
    gameDisplay.action(ACTION::GotAtk, dmg, &dwarf, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "W deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by an elf
void PlayerCharacter::attackedBy(Elf &elf)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * elf.getAtk());
    this->setHp(this->getHp() - 2*dmg);

    gameDisplay.action(ACTION::GotAtk, dmg, &elf, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "E deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by an orcs
void PlayerCharacter::attackedBy(Orcs &orcs)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * orcs.getAtk());
    this->setHp(this->getHp() - dmg);

    gameDisplay.action(ACTION::GotAtk, dmg, &orcs, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "O deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by a merchant
void PlayerCharacter::attackedBy(Merchant &merchant)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * merchant.getAtk());
    this->setHp(this->getHp() - dmg);
    
    gameDisplay.action(ACTION::GotAtk, dmg, &merchant, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "M deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by a dragon
void PlayerCharacter::attackedBy(Dragon &dragon)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * dragon.getAtk());
    this->setHp(this->getHp() - dmg);
    
    gameDisplay.action(ACTION::GotAtk, dmg, &dragon, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "D deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

// Attacked by a halfling
void PlayerCharacter::attackedBy(Halfling &halfling)
{
    int dmg = ceil(100.0/(100 + this->getDef()) * halfling.getAtk());
    this->setHp(this->getHp() - dmg);
    
    gameDisplay.action(ACTION::GotAtk, dmg, &halfling, this);
    // std::string sdmg = std::to_string(dmg);
    // std::string s = "L deals " + sdmg + " damage to PC. ";
    // gameDisplay.newAction(s);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}

void PlayerCharacter::slain(char race){
    int gold = rand() % 2 + 1;
    this->setScore(score + gold);

    std::string s = "PC slains ";
    s.push_back(race);
    s += ". ";
    gameDisplay.newAction(s, false);

    if (this->getHp() == 0) gameDisplay.action(ACTION::Die);
}


void PlayerCharacter::resetPotion()
{
    potions = std::make_shared<Potion>();
}
