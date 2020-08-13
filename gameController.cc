#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "gameController.h"
#include "enemyCharacter.h"
#include "potion.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "architect.h"
#include "treasure.h"
#include "display.h"

using namespace std;

void GameController::pcNotifyAround()
// pc will notify around when a round is finished
{
	int x = pc->getXCoordinate();
	int y = pc->getYCoordinate();
	pc->notify(board.floor[x+1][y].back());
	pc->notify(board.floor[x-1][y].back());
	pc->notify(board.floor[x][y-1].back());
	pc->notify(board.floor[x][y+1].back());
	pc->notify(board.floor[x-1][y-1].back());
	pc->notify(board.floor[x-1][y+1].back());
	pc->notify(board.floor[x+1][y-1].back());
	pc->notify(board.floor[x+1][y+1].back());
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
		if (board.getChar(x, y) == '.' && board.getChamberInd(x, y) == ind)
		{
			break;
		}
	}
	auto stair = make_shared<Architect>(x, y, '\\', ind);
	board.replace(stair);
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
		board.setRow(newRow);

		while (iss.get(c))
		// assume in the file, there can only be ' ', '.', '-', '|', '+', '#'
		{
			vector<shared_ptr<GameElement>> sqr;
			if (c == '.')
			{
				//cout << row << " ";
				//cout << col << endl;
				int leftInd = board.getChamberInd(row, col-1);
				int upInd = board.getChamberInd(row-1, col);
				int rightInd = 0;
				int ro = row-1;
				int co = col;
				while (board.getChar(ro, co) == '-' || board.getChar(ro, co) == '|' || board.getChar(ro, co) == '+')
				{
					++co;
				}
				if (board.getChar(ro, co) == '.')
				{
					rightInd = board.getChamberInd(ro, co);
				}
				int chamberInd = max(leftInd, upInd);
				chamberInd = max(chamberInd, rightInd);
				if (chamberInd == 0)
				{
					chamberInd = ind;
					++ind;
				}
				sqr.push_back(make_shared<Architect>(row, col, c, chamberInd));
			}
			else
			{
				sqr.push_back(make_shared<Architect>(row, col, c, 0));
			}
			board.floor[board.floor.size()-1].push_back(sqr);
			++col;
		}
		col = 0;
		if (line[1] == '-' && row >= 1) break;
		++row;
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
	while (board.floor[x][y].back()->getChar() != '.')
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

void GameController::setGameElement()
{
	spawnStair();
	board.spawnPotion();	// potion then gold
	board.spawnGold();
	board.spawnEnemy();
	pcNotifyAround();
}

void GameController::moveEnemy()
{
	int pc_x = pc->getXCoordinate();
	int pc_y = pc->getYCoordinate();
	board.moveEnemy(pc_x, pc_y);
	pcNotifyAround();
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
	else if (c == 'G')
	{
		shared_ptr<Treasure> t = dynamic_pointer_cast<Treasure>(board.floor[x][y].back());
		pc->pickup(t);
		board.revert(x, y);
		board.revert(pc);
		pc->setXCoordinate(x);
		pc->setYCoordinate(y);
		board.replace(pc);	// if PC
	}
}

void GameController::drinkPotion(string direc)
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

	if (board.getChar(x, y) == 'P')
	{
		shared_ptr<Potion> p = dynamic_pointer_cast<Potion>(board.floor[x][y].back());
		pc->drink(p);
	}
}

void GameController::attackEnemy(string direc)
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

	if (board.getChar(x, y) == 'E')
	{
		shared_ptr<EnemyCharacter> e = dynamic_pointer_cast<EnemyCharacter>(board.floor[x][y].back());
		pc->attack(*e);
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

void GameController::flushDisplay()
{
    gameDisplay.clearAction();
    gameDisplay.move(board.floor);
    gameDisplay.getNotified(pc.get());
    cout << gameDisplay;
}
