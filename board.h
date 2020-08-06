#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "gameElement.h"

public Board
{
	private:
		std::vector<std::vector<std::vector<std::shared_ptr<GameElement>>>> board;
		std::map<std::shared_ptr<EnemyCharacter>, int> enemyList;

	public:
		~Board();

		std::string getType(int x, int y); // get game element type at (x,y)

		void swap(int x1, int y1, int x2, int y2); // swap two items
		void spawnEnemy();
		void spawnItem();
		void moveEnemy();
		std::vector<std::string> getEnemyList();
}

#endif
