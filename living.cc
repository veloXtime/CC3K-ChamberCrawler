#include "living.h"

// Constructor
Living::Living(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp)
    : GameElement{x,y,c}, race{race}, hp{hp}, atk{atk}, def{def}, max_hp{max_hp} {}


// Retreive the hp of the living object
int Living::getHp() const{
    return hp;
}

// Get max hp of the living object
int Living::getMaxHp() const{
    return max_hp;
}

// Retreive the race of the living object
std::string Living::getRace() const{
    return race;
}

// Retreive the atk of the living object
int Living::getAtk() const{
    return atk;
}

// Retreive the def of the living object
int Living::getDef() const{
    return def;
}

// Set hp to value v
void Living::setHp(int v){
    if (v < 0) hp = 0;
    else if (v > max_hp) hp = max_hp;
    else hp = +v;
}

// Set atk to value v
void Living::setAtk(int v){
    if (v < 0) atk = 0;
    else atk = v;
}

// Set def to value v
void Living::setDef(int v){
    if (v < 0) def = 0;
    else def = v;
}

