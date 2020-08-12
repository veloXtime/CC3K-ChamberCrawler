#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::vector;

class GameElement;
class Potion;
class PlayerCharacter;
class EnemyCharacter;
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

class display
{
    //char board[20][80];
    std::string status, hp, atk, def, actline; //floor is in the same line as race
    
    
    public:

        void move(vector<vector<vector<shared_ptr<GameElement>>>>&);

        // called when the status line changes
        void getNotified(PlayerCharacter*);

		// called for moves, win, die
        void action(ACTION act);

		void action(ACTION, int);

		void action(ACTION, int damage, PlayerCharacter*, EnemyCharacter*);

		// append a new action message, take precedence over standard messages
		void newAction(std::string s, bool preced);

		// clear action string
		void clearAction();

		// return the corresponding string of act
        std::string interpAction(ACTION act);

		
        void flush();


};


std::ostream& operator<<(std::ostream& out, ACTION ac);

extern display gameDisplay;

#endif
