#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include <memory>
#include "gameElement.h"

using std::vector;
using std::array;
using std::shared_ptr;
using std::string;

class GameController;
class EnemyCharacter;
class Board
{
	private:
		int level = 1;
		vector<vector<vector<shared_ptr<GameElement>>>> floor;
		vector<shared_ptr<EnemyCharacter>> enemyList;

		void spawnItem();	//
		void spawnEnemy();	//
		void spawnOnePotion(int x, int y, int prob);
		void spawnGold();
		void spawnOneEnemy(int x, int y, int prob);

		void moveEnemy(int pc_x, int pc_y);	// complete
		void moveOneEnemy(std::shared_ptr<EnemyCharacter> e);	// complete
		// void movePC();
		void revert(std::shared_ptr<GameElement> ge);		// complete
		void replace(std::shared_ptr<GameElement> ge);		// complete

		void setLevel(int lv);	// complete
		void setRow(vector<vector<shared_ptr<GameElement>>> newRow);// complete

	public:
		int getLevel();		// complete
		int getChamberInd(int x, int y);	// complete
		char getChar(int x, int y); // get game element type at (x,y), complete

		friend GameController;
};


extern Board board;
#endif
