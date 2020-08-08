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
		void spawnEnemy(Board & board);	// also changes the enemyList
		void spawnItem(Board & board);

	public:
		void setFloor(istream & in);
		void setLevel(int lv);
		void spawnPC(char c);
		void setGameElement();
		void moveEnemy();
		void movePC(std::string direc);
		void drinkPotion(std::string direc);
		void attackEnemy(std::string direc);
		void displayLose();
		void displayWin();
		void newBoard(board.getLevel()+1);
		bool levelComplete();
};

#endif
