#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "board.h"
#include "enemyCharacter.h"
#include "architect.h"
using namespace std;

void Board::spawnItem()
{
	
}

void Board::spawnEnemy()
{
	int row = board.floor.size();
	int col = board.floor[0].size();
	srand (time(NULL));
	int x = 0;
	int y = 0;
	while (floor[x][y].back()->getChar() != '.')
	{
		x = rand() % row;
		y = rand() % col;
	}
}

// helper struct for use of sorting algorithm
struct sortCompare 
{
	bool operator()(shared_ptr<EnemyCharacter> e1, shared_ptr<EnemyCharacter> e2) 
	{
		int x1 = e1->getXCoordinate();
		int y1 = e1->getYCoordinate();
		int x2 = e2->getXCoordinate();
		int y2 = e2->getYCoordinate();
		if (x1 < x2)
		{
			return true;
		}
		if (x1 == x2)
		{
			return (y1 < y2);
		}
		return false;
	}
} compare;


void Board::moveEnemy(int pc_x, int pc_y)
{
	int x = 0;
	int y = 0;
	for (auto &e : enemyList)
	{
		x = e->getXCoordinate();
		y = e->getYCoordinate();
		if (x >= pc_x+1 || x <= pc_x-1 || y >= pc_y+1 || y <= pc_y-1)
		// if enemy is not near pc, then move
		{
			revert(e);
		}
	}
	for (auto &e: enemyList)
	{
		moveOneEnemy(e);
	}
	sort(enemyList.begin(), enemyList.end(), compare);
}

void Board::moveOneEnemy(std::shared_ptr<EnemyCharacter> e)
{
	int x = e->getXCoordinate();	// x and y will never be at border
	int y = e->getYCoordinate();
	if (getChar(x, y) == e->getChar())	// enemy was near pc, no change
	{
		return;
	}
	else
	{
		vector<pair<int,int>> unoccupied;
		if (getChar(x, y-1) == '.') unoccupied.push_back(make_pair(x,y-1));
		if (getChar(x, y+1) == '.') unoccupied.push_back(make_pair(x, y+1));
		if (getChar(x-1, y) == '.') unoccupied.push_back(make_pair(x-1, y));
		if (getChar(x+1, y) == '.') unoccupied.push_back(make_pair(x+1, y));
		if (getChar(x-1, y+1) == '.') unoccupied.push_back(make_pair(x-1, y+1));
		if (getChar(x-1, y-1) == '.') unoccupied.push_back(make_pair(x-1, y-1));
		if (getChar(x+1, y+1) == '.') unoccupied.push_back(make_pair(x+1, y+1));
		if (getChar(x+1, y-1) == '.') unoccupied.push_back(make_pair(x+1, y-1));
		int count = unoccupied.size();
		if (count != 0)
		{
			srand (time(NULL));
			int random = rand() % count;
			x = unoccupied[random].first;
			y = unoccupied[random].second;
		}
	}
	e->setXCoordinate(x);
	e->setYCoordinate(y);
	replace(e);
}

void Board::revert(std::shared_ptr<GameElement> ge)
// change return type to gameElement?
{
	int x = ge->getXCoordinate();
	int y = ge->getYCoordinate();
	floor[x][y].pop_back();
}

void Board::replace(std::shared_ptr<GameElement> ge)
{
	int x = ge->getXCoordinate();
	int y = ge->getYCoordinate();
	floor[x][y].push_back(ge);
}


int Board::getLevel()
{
	return level;
}

void Board::setLevel(int lv)
{
	level = lv;
}

char Board::getChar(int x, int y) // get game element type at (x,y)
{
	return floor[x][y].back()->getChar();
}

int Board::getChamberInd(int x, int y)
{
	if (floor[x][y].back()->getChar() == '.')
	{
		shared_ptr<Architect> tile = dynamic_pointer_cast<Architect>(floor[x][y].back());
		return tile->getChamberInd();
	}
	return 0;
}

void Board::setRow(vector<vector<shared_ptr<GameElement>>> newRow)
{
	floor.push_back(newRow);
}
