#include <iostream>
#include "display.h"
#include "potion.h"
#include "board.h"
using std::string;
using std::to_string;


display::display()
{
    for(int i = 0; i < 25; i++)
    {
        boardBuffer[i][79] = 0;
    }
}
void display::move(vector<vector<vector<shared_ptr<GameElement>>>>& b)
{
    for(int x = 0; x < b.size(); ++x)
    {
        for(int y = 0; y < b[x].size(); ++y)
        {

            boardBuffer[x][y] = b[x][y].back()->getChar();
        }
    }
}

// called when the status line changes
void display::getNotified(PlayerCharacter* pc)
{
    status = "Race: " + pc->getRace() + " Gold: " + std::to_string(pc->getScore()) + "\n";
    string fill = string(' ', 79 - 7 - status.length());
    status = status + fill + "Floor: " + std::to_string(board.getLevel());

    hp = "HP: " + std::to_string(pc->getHp());
    atk = "ATK: " + std::to_string(pc->getAtk());
    def = "DEF: " + std::to_string(pc->getDef());
}

// called for moves, win, die
void display::action(ACTION act)
{
    switch(act)
	{
		case ACTION::MoveEA: 
			actline +="You moved east. "; break;
		case ACTION::MoveWE:
			actline +="You moved west. "; break;
		case ACTION::MoveNO:
			actline +="You moved north. "; break;
		case ACTION::MoveSO:
			actline +="You moved south. "; break;
		case ACTION::MoveNE:
			actline +="You moved northeast. "; break;
		case ACTION::MoveNW:
			actline +="You moved northwest. "; break;
		case ACTION::MoveSE:
			actline +="You moved southeast. "; break;
		case ACTION::MoveSW:
			actline +="You moved southwest. "; break;
		case ACTION::ReachStair:
			actline +="You reached the stair of this floor. "; break;
		case ACTION::SeePotion:
			actline +="You saw an unknown potion. "; break;
		case ACTION::SeeGold:
			actline +="You saw some gold. "; break;
		case ACTION::Win:
			actline +="You win. "; break;
		case ACTION::Die:
			actline +="You died. "; break;
		// case AtkEnemy:	// take in enemy and damage?
		// case DrinkP: // take in potion?
		// case PickG:	// take in gold amount?
        default: break;
    }}

void display::action(ACTION act, int v)
{
    switch(act)
    {
        case ACTION::PickG:
            actline += "You picked up " + to_string(v) + " piece(s) of gold. ";
            break; 
        default: break;
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
        actline += "You dealed " + to_string(damage) + " damage to " + b->getRace() + ". ";
    }
}

// append a new action message
void display::newAction(std::string s, bool first)
{
    if(first) actline = s + actline;
    else actline = actline + s;
}

// clear action string
void display::clearAction()
{
    actline.clear();
}

std::ostream& operator<<(std::ostream& out, const display& ac)
{
    for(int i = 0; i < 25; ++i)
    {
        out << ac.boardBuffer[i] << '\n';
    }
    out << ac.status << '\n' << ac.hp << '\n' << ac.atk << '\n' 
    << ac.def << '\n' << ac.actline << '\n';

    return out;
}

display gameDisplay{}; 
