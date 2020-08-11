#include "display.h"
#include "potion.h"
#include "action.h"


void display::move(vector<vector<vector<shared_ptr<GameElement>>>>){

}

// called when the status line changes
void display::getNotified(PlayerCharacter*){

}

// called for moves, win, die
void display::action(ACTION act){
    actline += interpAction(act);
}

// append a new action message
void display::newAction(std::string s){
    actline += s;
}

// clear action string
void display::clearAction(){
    actline.clear();
}

// return the corresponding string of act
std::string display::interpAction(ACTION act){
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
		case ReachStair:
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


std::ostream& operator<<(std::ostream& out, ACTION ac)
{
	switch(ac)
	{
		case MoveEA: 
			out << "PC moves east";
			break;
		case MoveWE:
			out << "PC moves west";
			break;
		case MoveNO:
			out << "PC moves north";
			break;
		case MoveSO:
			out << "PC moves south";
			break;
		case MoveNE:
			out << "PC moves northeast";
			break;
		case MoveNW:
			out << "PC moves northwest";
			break;
		case MoveSE:
			out << "PC moves southeast";
			break;
		case MoveSW:
			out << "PC moves southwest";
			break;
		case ReachStair:
			out << "reaches the stair of this floor";
			break;
		case SeePotion:
			out << "sees an unknown potion";
			break;
		case SeeGold:
			out << "sees some gold";
			break;
		case Win:
			out << "you win";
			break;
		case Die:
			out << "you died";
			break;
}
	return out;
}
