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
class Treasure;
class Potion;

class Board
{
	private:
		int level = 0;
		vector<vector<vector<shared_ptr<GameElement>>>> floor;
		vector<shared_ptr<EnemyCharacter>> enemyList;

	public:
		void spawnPotion();	//
		void spawnOnePotion(int x, int y, int prob);

		void spawnGold();

		void spawnEnemy();	// complete
		void spawnOneEnemy(int x, int y, int prob);	// complete

		void moveEnemy(int pc_x, int pc_y);	// complete
		void moveOneEnemy(std::shared_ptr<EnemyCharacter> e);	// complete

		void setLevel(int lv);	// complete
		void setRow(vector<vector<shared_ptr<GameElement>>> newRow);// complete

		int getLevel();		// complete

		void revert(std::shared_ptr<GameElement> ge);		// complete
		void revert(int x, int y);		// complete

		void enemyDeath(shared_ptr<EnemyCharacter> e, int, int);
		void replace(std::shared_ptr<GameElement> ge);		// complete
		int getChamberIndHelp(int x, int y);
		int getChamberInd(int x, int y);	// complete
		char getChar(int x, int y); // get game element type at (x,y), complete

		friend GameController;
};

extern Board board;

#endif
