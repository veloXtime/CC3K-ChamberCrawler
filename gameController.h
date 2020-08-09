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
		//void spawnEnemy(Board & board);	// also changes the enemyList
		//void spawnItem(Board & board);
		int pcChamber = 0;
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
		void drinkPotion(std::string direc);
		void attackEnemy(std::string direc);
		void displayLose();
		void displayWin();
		//void newBoard(int level);
		
		bool levelComplete();		// complete
		void setPCChamber(int chamberInd);	// complete
};

#endif
