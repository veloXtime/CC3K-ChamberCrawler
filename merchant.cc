#include <cmath>
#include "merchant.h"
#include "playerCharacter.h"
#include "display.h"
#include "board.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

// Constructor
<<<<<<< HEAD
Merchant::Merchant(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp)
: EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {slained = false;}
=======
Merchant::Merchant(int x, int y, char c = 'M', std::string race = "merchant", 
                   int hp = 30, int atk = 70, int def = 5, int max_hp = 30)
                   : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {hostile = false;}
>>>>>>> 9dd837e4808c49ddabe83ba3b26374612f35d4c6

// If any merchant has been attacked
bool Merchant::getHostile(){
    return hostile;
}

// Upon death of a merchant slained by pc
void Merchant::death(PlayerCharacter &pc){
    pc.slain('M');

    std::string s = "Some gold is left on the floor. All merchants are now hostile to PC. ";
    gameDisplay.newAction(s);

    board.revert(x, y);

	auto mh = std::make_shared<Treasure>(x, y, TreasureType::Merchant);
    board.replace(mh);
}

// Override notify
void Merchant::getNotified(PlayerCharacter &pc) {
    if (hostile) this->attack(pc);
}

// Destructor
Merchant::~Merchant() {}


// Attacked by a shade
void Merchant::attackedBy(Shade &shade){
    hostile = true;
    int dmg = ceil(100/(100 + this->getDef()) * shade.getAtk());
    this->setHp(this->getHp() - dmg);

    std::string sdmg = std::to_string(dmg);
    std::string shp = std::to_string(this->getHp());
    std::string s = "PC deals " + sdmg + " to ";
    s.push_back(this->getChar());
    s += " (" + shp + " HP). ";
    gameDisplay.newAction(s);
}

// Attacked by a drow
void Merchant::attackedBy(Drow &drow){
    hostile = true;
    int dmg = ceil(100/(100 + this->getDef()) * drow.getAtk());
    this->setHp(this->getHp() - dmg);

    std::string sdmg = std::to_string(dmg);
    std::string shp = std::to_string(this->getHp());
    std::string s = "PC deals " + sdmg + " to ";
    s.push_back(this->getChar());
    s += " (" + shp + " HP). ";
    gameDisplay.newAction(s);
}

// Attacked by a vampire
void Merchant::attackedBy(Vampire &vampire){
    hostile = true;
    int dmg = ceil(100/(100 + this->getDef()) * vampire.getAtk());
    this->setHp(this->getHp() - dmg);
    vampire.setHp(vampire.getHp() + 5);

    std::string sdmg = std::to_string(dmg);
    std::string shp = std::to_string(this->getHp());
    std::string s = "PC deals " + sdmg + " to ";
    s.push_back(this->getChar());
    s += " (" + shp + " HP). ";
    gameDisplay.newAction(s);
}

// Attacked by a troll
void Merchant::attackedBy(Troll &troll){
    hostile = true;
    int dmg = ceil(100/(100 + this->getDef()) * troll.getAtk());
    this->setHp(this->getHp() - dmg);

    std::string sdmg = std::to_string(dmg);
    std::string shp = std::to_string(this->getHp());
    std::string s = "PC deals " + sdmg + " to ";
    s.push_back(this->getChar());
    s += " (" + shp + " HP). ";
    gameDisplay.newAction(s);
}

// Attacked by a goblin
void Merchant::attackedBy(Goblin &goblin){
    hostile = true;
    int dmg = ceil(100/(100 + this->getDef()) * goblin.getAtk());
    this->setHp(this->getHp() - dmg);

    std::string sdmg = std::to_string(dmg);
    std::string shp = std::to_string(this->getHp());
    std::string s = "PC deals " + sdmg + " to ";
    s.push_back(this->getChar());
    s += " (" + shp + " HP). ";
    gameDisplay.newAction(s);
}

