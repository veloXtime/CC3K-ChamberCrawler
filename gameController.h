#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "board.h"
#include "playerCharacter.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>

class GameController
{
    private:
        std::shared_ptr<PlayerCharacter> pc;
        int pcChamber = 0;
        // the chamber of which pc is spawned into, initialized as 0

        int stairX;
        int stairY;

        void spawnStair();	// complete
        void pcNotifyAround();	// complete

    public:
        void resetFloor(std::istream & in);	// complete
        void setLevel(int lvl);			// complete
        void spawnPC(char c);			// complete
        void setGameElement();			// complete

        void moveEnemy();				// complete

        void movePC(std::string direc);	// complete
        void drinkPotion(std::string direc);	// complete
        void attackEnemy(std::string direc);	// complete
        void displayLose();
        void displayWin();
        //void newBoard(int level);

        bool levelComplete();		// complete
        void setPCChamber(int chamberInd);	// complete

        void flushDisplay();
};

#endif
