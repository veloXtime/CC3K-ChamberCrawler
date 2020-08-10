#include "enemyCharacter.h"
#include <math.h>
#include "playerCharacter.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

// Constructor
EnemyCharacter::EnemyCharacter(int x, int y, char c, std::string race, 
                               int hp, int atk, int def, int max_hp)
                               : Living(x, y, c, race, hp, atk, def, max_hp) {}

// Attacking another character
void EnemyCharacter::attack(PlayerCharacter &pc){
    if (this->getChar() == 'H'){
        Human& human = dynamic_cast<Human&> (*this);
        pc.attackedBy(human);
    }
    else if (this->getChar() == 'W'){
        Dwarf& dwarf = dynamic_cast<Dwarf&> (*this);
        pc.attackedBy(dwarf);
    }
    else if (this->getChar() == 'E'){
        Elf& elf = dynamic_cast<Elf&> (*this);
        pc.attackedBy(elf);
    }
    else if (this->getChar() == 'O'){
        Orcs& orcs = dynamic_cast<Orcs&> (*this);
        pc.attackedBy(orcs);
    }
    else if (this->getChar() == 'M'){
        Merchant& merchant = dynamic_cast<Merchant&> (*this);
        pc.attackedBy(merchant);
    }
    else if (this->getChar() == 'D'){
        Dragon& dragon = dynamic_cast<Dragon&> (*this);
        pc.attackedBy(dragon);
    }
    else if (this->getChar() == 'L'){
        Halfling& halfling = dynamic_cast<Halfling&> (*this);
        pc.attackedBy(halfling);
    }
    
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

EnemyCharacter::~EnemyCharacter() {}
