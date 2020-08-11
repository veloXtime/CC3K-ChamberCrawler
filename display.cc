#include "display.h"
#include "potion.h"


void Display::move(vector<vector<vector<shared_ptr<GameElement>>>>);

// called when the status line changes
void Display::getNotified(PlayerCharacter*);

// called for moves, win, die
void Display::action(ACTION act){
    action += interpAction(act);
}

// called for using potion
void Display::action(ACTION act, Potion& p, int val){
    PotionHP& potion = dynamic_cast<PotionHP&> (p);
    if (potion){
        if (val > 0) action += "PC uses RH. ";
        else action += "PC uses PH. ";
    }
    else{
        PotionAtk& potion = dynamic_cast<PotionAtk&> (p);
        if (potion){
            if (val > 0) action += "PC uses BA. ";
            else action += "PC uses WA. ";
        }
        else{
            PotionDef& potion = dynamic_cast<PotionDef&> (p);
            if (potion){
                if (val > 0) action += "PC uses BD. ";
                else action += "PC uses WD. ";
            }
    }
}

// called for attacking enemy
void Display::action(ACTION act, int dmg, char race, int hp);

// called for killiong enemy
void Display::action(ACTION act, char race);

// return the corresponding string of act
std::string Display::interpAction(ACTION act){
    switch(act)
	{
		case MoveEA: 
			return "PC moves east. ";
		case MoveWE:
			return "PC moves west. ";
		case MoveNO:
			return "PC moves north. ";
		case MoveSO:
			return "PC moves south. ";
		case MoveNE:
			return "PC moves northeast. ";
		case MoveNW:
			return "PC moves northwest. ";
		case MoveSE:
			return "PC moves southeast. ";
		case MoveSw:
			return "PC moves southwest. ";
		case SeeStair:
			return "PC reaches the stair of this floor. ";
		case SeePotion:
			return "PC sees an unknown potion. ";
		case SeeGold:
			return "PC sees some gold. ";
		case Win:
			return "You win. ";
		case Die:
			return "You died. "
		// case AtkEnemy:	// take in enemy and damage?
		// case DrinkP: // take in potion?
		// case PickG:	// take in gold amount?
    }
}
