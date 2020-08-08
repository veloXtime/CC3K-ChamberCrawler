#include <algorithm>
#include "gameController.h"
using namespace std;

void GameController::resetFloor(istream & in)
{
	board.floor.clear();
	++board.level;
	int row = 0;
	int col = 0;
	int ind = 1;
	string line = "";

	while (getline(in, line))
	{
		istringstream iss {line};
		char c;
		vector<vector<shared_ptr<GameElement>>> newRow;

		while (iss.get(c))	
		// assume in the file, there can only be ' ', '.', '-', '|', '+', '#'
		{
			vector<shared_ptr<GameElement>> sqr;
			if (c == '.')
			{
				int leftInd = board.getChamberInd(row, col-1);
				int upInd = board.getChamberInd(row-1, col);
				int chamberInd = max(leftInd, upInd);
				if (chamberInd == 0)
				{
					chamberInd = ind;
					++ind;
				}
				sqr.push_back(make_shared<Floor>(row, col, c, chamberInd));
			}
			else
			{
				sqr.push_back(make_shared<Floor>(row, col, c, 0));
			}
			newRow.push_back(sqr);
			++col;
		}
		board.setRow(newRow);
		col = 0;
		++row;
		if (line[1] == '-' && row >= 1) break;
	}
}


void GameController::setLevel(int lvl)
{
	board.setLevel(lvl);
}

void spawnPC(char c)
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
	if (c == 's')
	{
		pc = make_shared<Shade>(x, y);
	}
	else if (c == 'd')
	{
		pc = make_shared<Drow>(x, y);
	}
	else if (c == 'v')
	{
		pc = make_shared<Vampire>(x, y);
	}
	else if (c == 'g')
	{
		pc = make_shared<Goblin>(x, y);
	}
	else if (c == 't')
	{
		pc = make_shared<Troll>(x, y);
	}
	board.replace(pc);
}

void GameController::setGameElement();
{
	board.spawnStair();
	board.spawnItem();	// potion then gold
	board.spawnEnemy();
}

void GameController::moveEnemy()
{
	board.moveEnemy();
}

void GameController::movePC(string direc)
{
	int x = pc->getXCoordinate();
	int y = pc->getYCoordinate();

	if (direct == "no")
	{
		--x;
	}
	else if (direct == "so")
	{
		++x;
	}
	else if (direct == "ea")
	{
		++y;
	}
	else if (direct == "we")
	{
		--y;
	}
	else if (direct == "ne")
	{
		--x;
		++y;
	}
	else if (direct == "nw")
	{
		--x;
		--y;
	}
	else if (direct == "se")
	{
		++x;
		++y;
	}
	else if (direct == "sw")
	{
		++x;
		--y;
	}

	char c = board.getChar(x,y);
	if (c == '.' || c == '+' || c == '#')
	{
		board.revert(pc);
		pc.setXCoordinate(x);
		pc.setYCoordinate(y);
		board.replace(pc);
	}
	if (c == 'G')
	{
		board.pickGold();
	}
}

void GameController::drinkPotion(string direc)
{
}


void GameController::attackEnemy()
{
}

void GameController::displayLose()
{
}

void GameController::displayWin()
{
}

void GameController::GameController::
