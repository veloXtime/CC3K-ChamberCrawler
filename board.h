#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <array>
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
		int level = 0;
		vector<vector<vector<shared_ptr<GameElement>>>> floor;
		vector<shared_ptr<EnemyCharacter>, int, int> enemyList;

		void spawnEnemy();
		void spawnItem();
		void spawnStair();
		void spawnPC();
		void moveEnemy();
		void moveSingleEnemy(std::shared_ptr<EnemyCharacter> e);
		void movePC();
		void revert(std::shared_ptr<GameElement> ge);
		void replace(std::shared_ptr<GameElement> ge);

	public:
		Board();

		int getLevel();
		char getChar(int x, int y); // get game element type at (x,y)
		int getChamberInd(int x, int y);
		void pushRow(vector<vector<shared_ptr<GameElement>>> newRow);
		vector<string> getEnemyList();

		friend GameController;
};


extern Board board {};
#endif
