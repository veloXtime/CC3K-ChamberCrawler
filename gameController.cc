#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "gameController.h"

using namespace std;

void GameController::pcNotifyAround()
{
	int x = pc->getXCoordinate();
	int y = pc->getYCoordinate();
	pc.notify(board.floor[x+1][y].back());
	pc.notify(board.floor[x-1][y].back());
	pc.notify(board.floor[x][y-1].back());
	pc.notify(board.floor[x][y+1].back());
	pc.notify(board.floor[x-1][y-1].back());
	pc.notify(board.floor[x-1][y+1].back());
	pc.notify(board.floor[x+1][y-1].back());
	pc.notify(board.floor[x+1][y+1].back());
}

void GameController::spawnStair()
{
	srand(time(NULL));
	int ind = pcChamber;
	while (ind == pcChamber)
	{
		ind = rand() % 5 + 1;
	}
	int x = 0;
	int y = 0;
	while (true)
	{
		x = rand() % board.floor.size();
		y = rand() % board.floor[0].size();
		if (board.getChar(x, y) == '.' && board.getChamberInd(x, y) == pcChamber)
		{
			break;
		}
	}
	auto stair = make_shared<Architect>(x, y, ind, '\\');
	replace(stair);
	stairX = x;
	stairY = y;
}

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

void GameController::spawnPC(char c)
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
	spawnStair();
	board.spawnItem();	// potion then gold
	board.spawnEnemy();
	pcNotifyAround();
}

void GameController::moveEnemy()
{
	int pc_x = pc->getXCoordinate();
	int pc_y = pc->getYCoordinate();
	board.moveEnemy(pc_x, pc_y);
}

void GameController::movePC(string direc)
{
	int x = pc->getXCoordinate();
	int y = pc->getYCoordinate();

	if (direc == "no") { --x; }
	else if (direc == "so") { ++x; }
	else if (direc == "ea") { ++y; }
	else if (direc == "we") { --y; }
	else if (direc == "ne") { --x; ++y; }
	else if (direc == "nw") { --x; --y; }
	else if (direc == "se") { ++x; ++y; }
	else if (direc == "sw") { ++x; --y; }

	char c = board.getChar(x,y);
	setPCChamber(board.getChamberInd(x,y));
	if (c == '.' || c == '+' || c == '#')
	{
		board.revert(pc);
		pc->setXCoordinate(x);
		pc->setYCoordinate(y);
		board.replace(pc);
	}
	if (c == 'G')
	{
		board.pickGold();
		board.replace(pc);	// if PC 
	}
}

void GameController::drinkPotion(string direc)
{
}

void GameController::attackEnemy(string direc)
{
	int x = pc->getXCoordinate();
	int y = pc->getYCoordinate();

	if (direc == "no")
	{
		--x;
	}
	else if (direc == "so")
	{
		++x;
	}
	else if (direc == "ea")
	{
		++y;
	}
	else if (direc == "we")
	{
		--y;
	}
	else if (direc == "ne")
	{
		--x;
		++y;
	}
	else if (direc == "nw")
	{
		--x;
		--y;
	}
	else if (direc == "se")
	{
		++x;
		++y;
	}
	else if (direc == "sw")
	{
		++x;
		--y;
	}

}

void GameController::displayLose()
{
}

void GameController::displayWin()
{
}

bool GameController::levelComplete()
{
	return (pc->getXCoordinate() == stairX && pc->getXCoordinate() == stairY);
}

void GameController::setPCChamber(int chamberInd)
{
	pcChamber = chamberInd;
}
