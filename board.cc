#include <cstdlib>
#include <ctime>
#include "board.h"

void Board::spawnEnemy()
{
}

void Board::spawnItem();

void Board::spawnStair();

void spawnPC();

void movePC();


void Board::moveEnemy()
{
	int x = 0;
	int y = 0;
	for (auto &e : enemyList)
	{
		x = e->getXCoordinate();
		y = e->getYCoordinate();
		revert(x,y);
	}
	for (auto &e: enemyList)
	{
		moveSingleEnemy(e);
	}
}

void Board::moveSingleEnemy(std::shared_ptr<Enemy> e)
{
	int x = e->getXCoordinate();	// x and y will never be at border
	int y = e->getYCoordinate();
	
	int left = ((board[x-1][y]->getChar() == '.') ? 1 : 0); // 1
	int right = ((board[x+1][y]->getChar() == '.') ? 1 : 0); // 2
	int up = ((board[x][y-1]->getChar() == '.') ? 1 : 0); // 3
	int down = ((board[x][y+1]->getChar() == '.') ? 1 : 0); // 4
	int count = left+right+up+down;

}

void revert(int x, int y)	// revert board at position (x,y) to floor 
// change return type to gameElement?
{
	board[x][y].pop();
}

void replace(std::shared_ptr<GameElement> ge)
{
	int x = ge->getXCoordinate();
	int y = ge->getYCoordinate();
	board[x][y].push_back(ge);
}

void GameElement::pushRow(vector<vector<shared_ptr<GameElement>>> newRow)
{
	board.push_back(newRow);
}


int Borad::getLevel()
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
		return floor[x][y].back()->getChamberInd();
	}
	else
	{
		return 0;
	}
}

void pushRow(vector<vector<shared_ptr<GameElement>>> newRow)
{
	floor.push_back(newRow);
}
