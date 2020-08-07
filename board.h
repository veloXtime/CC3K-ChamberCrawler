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
		//The third vector is a collection of game elements on the corresponding coordinate
		//Using fixed length array is probably easier
		vector<vector<array<shared_ptr<GameElement>, 3>>> board;
		
		std::map<shared_ptr<EnemyCharacter>, int> enemyList;

		void swap(int x1, int y1, int x2, int y2); // swap two items
		void spawnEnemy();
		void spawnItem();
		void moveEnemy();
	public:
		~Board();

		string getType(int x, int y); // get game element type at (x,y)
		int getFloor();
		
		vector<string> getEnemyList();

		friend GameController;
};


extern Board board;
#endif
