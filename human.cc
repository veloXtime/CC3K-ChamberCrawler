#include "human.h"
#include "display.h"
#include "playerCharacter.h"

// Constructor
Human::Human(int x, int y, char c, std::string race, 
             int hp, int atk, int def, int max_hp)
             : EnemyCharacter(x, y, c, race, hp, atk, def, max_hp) {}

// Destructor
Human::~Human() {}

// Upon death of a human slained by pc
void Human::death(PlayerCharacter &pc){
    pc.slain('H');

    std::string s = "Some gold is left on the floor. ";
    gameDisplay.newAction(s);
}
