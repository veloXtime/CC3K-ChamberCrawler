#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "board.h"
#include <iostream>
#include <istream>
#include <sstream>

class GameController
{
	private:
		std::shared_ptr<PlayerCharacter> pc;
		void spawnEnemy(Board & board);
		void spawnItem(Board & board);

	public:
		void setFloor(istream & in);
		void setLevel();
		void setGameElement();
		void moveEnemy();
		void drinkPotion();
		void attackEnemy();
		void displayLose();
		void displayWin();
		void newBoard(board.getLevel()+1);
		bool levelComplete();
		int getPCXCoord();
		int getPCYCoord();
		int getStairX();
		int getStairY();
};

#endif
