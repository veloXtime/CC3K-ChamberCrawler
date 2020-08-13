#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "board.h"
#include "enemyCharacter.h"
#include "architect.h"
#include "human.h"
#include "halfling.h"
#include "orcs.h"
#include "elf.h"
#include "dwarf.h"
#include "merchant.h"
#include "dragon.h"
#include "treasure.h"
#include "potion.h"
using namespace std;

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

void Board::spawnOnePotion(int x, int y, int prob)
{
	std::shared_ptr<Potion> potion;
	switch(prob)
	{
		case 1: potion = make_shared<PotionHP>(x, y, 10);  
				break; // Restore health (RH) break;
		case 2: potion = make_shared<PotionAtk>(x, y, 5); 
				break; // Boost Atk (BA): increase ATK by 5
		case 3: potion = make_shared<PotionDef>(x, y, 5); 
				break; // Boost Def (BD): increase Def by 5
		case 4: potion = make_shared<PotionHP>(x, y, -10); 
				break; // Poison health (PH): lose up to 10 HP 
		case 5: potion = make_shared<PotionAtk>(x, y, -5); 
				break; // Wound Atk (WA): decrease Atk by 5
		default: potion = make_shared<PotionDef>(x, y, -5); 
				break; // Wound Def (WD): decrease Def by 5
	}

	floor[x][y].push_back(potion);
}


void Board::spawnPotion()
{
	for (int i = 0; i < 10; ++i)
	{
		int prob = rand() % 6 + 1;
		int chamberId = rand() % 5 + 1;
		int x = rand() % floor.size();
		int y = rand() % floor[0].size();
		while (getChamberInd(x,y) != chamberId || board.getChar(x, y) != '.')
		{
			x = rand() % floor.size();
			y = rand() % floor[0].size();
		}
		spawnOnePotion(x, y, prob);
	}
}

void Board::spawnGold()
{
	for (int i = 0; i < 10; ++i)
	{
		int prob = rand() % 8 + 1;
		int chamberInd = rand() % 5 + 1;
		int x = rand() % floor.size();
		int y = rand() % floor[0].size();
		while (getChamberInd(x,y) != chamberInd)
		{
			x = rand() % floor.size();
			y = rand() % floor[0].size();
		}
		if (prob <= 5)
		{
			TreasureType tt = TreasureType::NORMAL_PILE;
			auto gold = make_shared<Treasure>(x, y, tt);
			floor[x][y].push_back(gold);
		}
		if (prob <= 6)
		{
			vector<pair<int, int>> unoccupied;
			while (true)
			{
				if (getChar(x, y-1) == '.') unoccupied.push_back(make_pair(x,y-1));
				if (getChar(x, y+1) == '.') unoccupied.push_back(make_pair(x, y+1));
				if (getChar(x-1, y) == '.') unoccupied.push_back(make_pair(x-1, y));
				if (getChar(x+1, y) == '.') unoccupied.push_back(make_pair(x+1, y));
				if (getChar(x-1, y+1) == '.') unoccupied.push_back(make_pair(x-1, y+1));
				if (getChar(x-1, y-1) == '.') unoccupied.push_back(make_pair(x-1, y-1));
				if (getChar(x+1, y+1) == '.') unoccupied.push_back(make_pair(x+1, y+1));
				if (getChar(x+1, y-1) == '.') unoccupied.push_back(make_pair(x+1, y-1));
				if (unoccupied.size() > 0) break;
				x = rand() % floor.size();
				y = rand() % floor[0].size();
				while (getChamberInd(x,y) != chamberInd)
				{
					x = rand() % floor.size();
					y = rand() % floor[0].size();
				}
			}
			auto gold = make_shared<DragonHoard>(x, y);
			floor[x][y].push_back(gold);
			int dra_x = unoccupied[0].first;
			int dra_y = unoccupied[0].second;
			auto dragon = make_shared<Dragon>(dra_x, dra_y);
			floor[dra_x][dra_y].push_back(dragon);
		}
		else
		{
			TreasureType tt = TreasureType::SMALL_PILE;
			auto gold = make_shared<Treasure>(x, y, tt);
			floor[x][y].push_back(gold);
		}
	}
}


void Board::spawnOneEnemy(int x, int y, int prob)
{
	if (prob <= 4)
	{
		auto enemy = make_shared<Human>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
	else if (prob <= 7)
	{
		auto enemy = make_shared<Dwarf>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
	else if (prob <= 12)
	{
		auto enemy = make_shared<Halfling>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
	else if (prob <= 14)
	{
		auto enemy = make_shared<Elf>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
	else if (prob <= 16)
	{
		auto enemy = make_shared<Orcs>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
	else 
	{
		auto enemy = make_shared<Merchant>(x, y);
		floor[x][y].push_back(enemy);
		enemyList.push_back(enemy);
	}
}

void Board::spawnEnemy()
{
	for (int i = 0; i < 20; ++i)
	{
		int prob = rand() % 18 + 1;
		int chamberId = rand() % 5 + 1;
		int x = rand() % floor.size();
		int y = rand() % floor[0].size();
		while (getChamberInd(x,y) != chamberId)
		{
			x = rand() % floor.size();
			y = rand() % floor[0].size();
		}
		spawnOneEnemy(x, y, prob);
	}
	sort(enemyList.begin(), enemyList.end(), compare);
}


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
			int random = rand() % count;
			x = unoccupied[random].first;
			y = unoccupied[random].second;
		}
	}
	e->setXCoordinate(x);
	e->setYCoordinate(y);
	replace(e);
}

void Board::revert(int x, int y)
{
	floor[x][y].pop_back();
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

void Board::enemyDeath(EnemyCharacter & e)
{
	char c = e.getChar();
	int x = e.getXCoordinate();
	int y = e.getYCoordinate();
	revert(x, y);
	TreasureType tt = TreasureType::NORMAL_PILE;
	auto g1 = std::make_shared<Treasure>(x, y, tt);
	replace(g1);

	if (c == 'H')
	{
		int chamberInd = getChamberInd(x, y);
		int x1 = rand() % floor.size();
		int y1 = rand() % floor[0].size();
		while (getChamberInd(x1,y1) != chamberInd)
		{
			x = rand() % floor.size();
			y = rand() % floor[0].size();
		}
		auto g2 = make_shared<Treasure>(x, y, tt);
		replace(g2);
	}
}

Board board{};
