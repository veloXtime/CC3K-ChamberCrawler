#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "board.h"
#include "playerCharacter.h"
#include "treasure.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>

class GameController
{
	private:
		std::shared_ptr<PlayerCharacter> pc = nullptr;
		int pcChamber = 0;
		// the chamber of which pc is spawned into, initialized as 0

		int stairX = 0;
		int stairY = 0;

		void spawnStair();	// complete
		void pcNotifyAround();	// complete

	public:
		void resetFloor(std::istream & in);	// complete
		void readFloor(std::istream & in, char race);	// complete
		void readGE(int, int, int, char, char,
				std::vector<std::shared_ptr<GameElement>> &, 
				std::vector<std::shared_ptr<Dragon>> &, 
				std::vector<std::shared_ptr<DragonHoard>> & dh);
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

		bool isEnded(); //whether the game should be ended
};

#endif
