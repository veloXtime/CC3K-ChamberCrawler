#include "enemyCharacter.h"
#include <math.h>
#include "playerCharacter.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

// Constructor
EnemyCharacter::EnemyCharacter(int x, int y, char c, std::string race, 
                               int hp, int atk, int def, int max_hp)
                               : Living(x, y, c, race, hp, atk, def, max_hp) {}

// Attacking another character
void EnemyCharacter::attack(PlayerCharacter &pc){
    pc.attackedBy(*this);
}

// Attacked by a shade
void EnemyCharacter::attackedBy(Shade &shade){
    int dmg = ceil(100/(100 + this->getDef()) * shade.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a drow
void EnemyCharacter::attackedBy(Drow &drow){
    int dmg = ceil(100/(100 + this->getDef()) * drow.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a vampire
void EnemyCharacter::attackedBy(Vampire &vampire){
    int dmg = ceil(100/(100 + this->getDef()) * vampire.getAtk());
    this->setHp(this->getHp() - dmg);
    vampire.setHp(vampire.getHp() + 5);
}

// Attacked by a troll
void EnemyCharacter::attackedBy(Troll &troll){
    int dmg = ceil(100/(100 + this->getDef()) * troll.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Attacked by a goblin
void EnemyCharacter::attackedBy(Goblin &goblin){
    int dmg = ceil(100/(100 + this->getDef()) * goblin.getAtk());
    this->setHp(this->getHp() - dmg);
}

// Upon death of an enemy slained by pc
void EnemyCharacter::death(PlayerCharacter &pc){
    pc.slain();
}

// Get notified by a pc
void EnemyCharacter::getNotified(PlayerCharacter & pc){
    this->attack(pc);

    // display message
}
