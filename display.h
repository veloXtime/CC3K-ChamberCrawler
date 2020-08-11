#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "action.h"

using std::shared_ptr;
using std::vector;

class GameElement;
class Potion;
class PlayerCharacter;
class Enemy;
class Treasure;

class display
{
    //char board[20][80];
    std::string status, hp, atk, def, actline; //floor is in the same line as race
    
    
    public:

        void move(vector<vector<vector<shared_ptr<GameElement>>>>);

        // called when the status line changes
        void getNotified(PlayerCharacter*);

		// called for moves, win, die
        void action(ACTION act);
		
		// append a new action message
		void newAction(std::string s);

		// clear action string
		void clearAction();

		// return the corresponding string of act
        std::string interpAction(ACTION act);


};


std::ostream& operator<<(std::ostream& out, ACTION ac);

extern display gameDisplay;

#endif
