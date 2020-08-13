#include "display.h"
#include "potion.h"
#include "board.h"
using std::string;
using std::to_string;


void display::move(vector<vector<vector<shared_ptr<GameElement>>>>& b)
{
    for(int x = 0; x < b.size(); ++x)
    {
        for(int y = 0; y < b[x].size(); ++y)
        {
            for(int i = 2; i >= 0; --i)
            {
                if(b[x][y][i] != nullptr)
                {
                    boardBuffer[x][y] = b[x][y][i]->getChar();
                    break;
                }
            }
        }
    }
}

// called when the status line changes
void display::getNotified(PlayerCharacter* pc)
{
    status = "Race: " + pc->getRace() + " Gold: " + std::to_string(pc->getScore());
    string fill = string(' ', 79 - 7 - status.length());
    status = status + fill + "Floor: " + std::to_string(board.getLevel());

    hp = "HP: " + std::to_string(pc->getHp());
    atk = "ATK: " + std::to_string(pc->getAtk());
    def = "DEF: " + std::to_string(pc->getDef());
}

// called for moves, win, die
void display::action(ACTION act){
    actline += interpAction(act);
}

void display::action(ACTION act, int v)
{
    switch(act)
    {
        case ACTION::PickG:
            actline += "You picked up " + to_string(v) + " piece(s) of gold. ";
            break; 
    }
}

void display::action(ACTION act, Potion* p)
{
    actline += "You drinked " + p->getType() + ". ";
}

void display::action(ACTION act, int damage, Living* a, Living* b)
{
    if(act == ACTION::GotAtk)
    {
        actline += a->getRace() + "dealed " + to_string(damage) + " damage to you. ";
    }
    else //AtkEnemy
    {
        actline += "You dealed " + to_string(damage) + " damage to " + b->getRace(); + ". ";
    }
}

// append a new action message
void display::newAction(std::string s, bool first)
{
    if(first) actline = s + actline;
    else actline = actline + s;
}

// clear action string
void display::clearAction(){
    actline.clear();
}


std::string display::interpAction(ACTION act){
    switch(act)
	{
		case ACTION::MoveEA: 
			return "PC moves east. ";
		case ACTION::MoveWE:
			return "PC moves west. ";
		case ACTION::MoveNO:
			return "PC moves north. ";
		case ACTION::MoveSO:
			return "PC moves south. ";
		case ACTION::MoveNE:
			return "PC moves northeast. ";
		case ACTION::MoveNW:
			return "PC moves northwest. ";
		case ACTION::MoveSE:
			return "PC moves southeast. ";
		case ACTION::MoveSW:
			return "PC moves southwest. ";
		case ACTION::ReachStair:
			return "PC reaches the stair of this floor. ";
		case ACTION::SeePotion:
			return "PC sees an unknown potion. ";
		case ACTION::SeeGold:
			return "PC sees some gold. ";
		case ACTION::Win:
			return "You win. ";
		case ACTION::Die:
			return "You died. ";
		// case AtkEnemy:	// take in enemy and damage?
		// case DrinkP: // take in potion?
		// case PickG:	// take in gold amount?
        default:
    }
}