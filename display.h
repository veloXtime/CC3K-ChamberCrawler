#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::vector;

class GameElement;
class Potion;
class PlayerCharacter;
class Enemy;
class Treasure;


enum class ACTION 
{
	MoveEA,
	MoveWE,
	MoveNO,
	MoveSO, 
	MoveNE,
	MoveNW,
	MoveSE,
	MoveSW,
	ReachStair,
	SeePotion,
	SeeGold,
	SeeEnemy,
	Win,
	Die,
	AtkEnemy,
	GotAtk,
	DrinkP,
	PickG,
};

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
		case MoveSw:
			out << "PC moves southwest";
			break;
		case SeeStair:
			out << "reaches the stair of this floor";
			break;
		case SeePotion:
			out << "sees an unknown potion";
			break;
		case SeeGold:
			out << "sees some gold";
			break;
		case SeeEnemy:
			out << "sees an enemy";
			break;
		case Win:
			out << "you win";
			break;
		case Die:
			out << "you died"
			break;
		// case AtkEnemy:	// take in enemy and damage?
		// case DrinkP: // take in potion?
		// case PickG:	// take in gold amount?
}
	return out;
}

class display
{
    //char board[20][80];
    std::string status, hp, atk, action; //floor is in the same line as race
    
    
    public:

        void move(vector<vector<vector<shared_ptr<GameElement>>>>);

        //called when the status line changes
        void getNotified(PlayerCharacter*);


        void action(ACTION);
        void action(ACTION, int, PlayerCharacter*, Enemy*);
        void action(ACTION, int, Enemy*, PlayerCharacter*);

};
