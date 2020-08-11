#include "human.h"
#include "display.h"

// Constructor
Human::Human(int x, int y, char c = 'H', std::string race = "human", 
             int hp = 140, int atk = 20, int def = 20, int max_hp = 140)
             : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Human::~Human() {}

// Upon death of a human slained by pc
void Human::death(PlayerCharacter &pc){
    pc.slain('H');

    std::string s = "Some gold is left on the floor. ";
    gameDisplay.newAction(s);
}