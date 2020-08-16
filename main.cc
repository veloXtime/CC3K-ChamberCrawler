#include "gameController.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "debug.h"


bool checkDirection(string inp)
{
    return (inp == "no" || inp == "so"
            || inp == "ea" || inp == "we"
            || inp == "ne" || inp == "nw"
            || inp == "se" || inp == "sw");
}

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		string argseed(argv[2]);
		stringstream ss(argseed);
		int seed;
		ss >> seed;
		srand(seed);
	}
	else srand(time(NULL));

	#ifdef DEBUG
	srand(3);
	#endif
	string fname = (argc > 1) ? argv[1] : "default.txt";
	auto in = std::make_shared<std::ifstream>(fname);
	int stillMode = 0;
	int dlc = 0;
	GameController GC;
	string line;

	char race = ' ';
	while (board.getLevel() <= 5)
	{
		//initialization
		if (board.getLevel() == 0)
		{
			std::cout << "Please select a race:\n";
			while (std::getline(std::cin, line))
			{
				std::istringstream iss{line};
				iss >> race;
				if (dlc){
					if (race == 's' || race == 'd' || race == 'v' || race == 'g' || race == 't' || race == 'h')
					{
						break;
					}
					if (race == 'q')
					{
						return 1;
					}
					if (std::cin.eof()) { return 1; }
				}
				else{
					if (race == 's' || race == 'd' || race == 'v' || race == 'g' || race == 't')
					{
						break;
					}
					if (race == 'q')
					{
						return 1;
					}
					if (std::cin.eof()) { return 1; }
				}
			}
		}

		if (fname == "default.txt")
		{
			GC.resetFloor(*in);
			if (board.getLevel() == 1) GC.spawnPC(race);
			GC.setGameElement();
		}
		else 
		{
			GC.readFloor(*in, race);
		}
		GC.flushDisplay();


		while (std::getline(std::cin, line))
		{
			std::istringstream iss{line};
			string inp, arg;
			iss >> inp;
			if (checkDirection(inp))
			{
				//cout << inp;
				GC.movePC(inp);
				if (GC.levelComplete())
				{
					if(board.getLevel() == GOALFLOOR)
					{
						GC.displayWin();
						if (dlc){
							GC.displayScoreboard();
						}
						return 0;
					}
					break;
				}
				if (!stillMode)
				{
					GC.moveEnemy();
				}
			}
			else if (inp == "u")
			{
				iss >> arg;
				if (checkDirection(arg))
				{
					GC.drinkPotion(arg);
				}
				if (!stillMode)
				{
					GC.moveEnemy();
				}
			}
			else if (inp == "a")
			{
				iss >> arg;
				if (checkDirection(arg))
				{
					GC.attackEnemy(arg);
				}
				if (!stillMode)
				{
					GC.moveEnemy();
				}
			}
			else if (inp == "f")
			{
				stillMode = 1 - stillMode;
				if (!stillMode)
				{
					GC.moveEnemy();
				}
			}
			else if (inp == "r")
			{
				in = std::make_shared<std::ifstream>(fname);
				GC.setLevel(0);
				stillMode = 0;
				break;
			}
			else if (inp == "q")
			{
				GC.displayLose();
				return 0;
			}
			else if (inp == "l")
			{
				dlc = 1 - dlc;
				if (dlc) cout << "DLC is on." << endl;
				else cout << "DLC is off." << endl;
			}
			
			GC.flushDisplay();
			if(GC.isEnded())
			{
				in = std::make_shared<std::ifstream>(fname);
				GC.setLevel(0);
				stillMode = 0;
				break;
			}
				
		}
	}

	return 0;
}
