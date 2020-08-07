#include "gameController.h"

bool checkDirection(string inp)
{
	return (inp == "no" || inp == "so" || inp == "ea" || inp == "we" 
				|| inp == "ne" || inp == "nw" || inp == "se" || inp == "sw");
}
int main(int argc, char* argv[])
{
	string fname = (argc > 1) ? argv[1] : "default.txt";
	auto in = make_shared<ifstream>(fname);

	bool stillModeOn = 0;
	GameController GC;
	while (board.getLevel() <= 5)
	{
		GC.setFloor(*in);	// contains display
		if (board.getLevel == 1) { GC.choosePC(); }
		GC.setGameElement();	// contains display

		string line;
		while (getline(cin, line))
		{
			istringstream iss{line};
			string inp, arg;
			iss >> inp;

			if (checkDirection(inp))
			{
				GC.movePC(inp);
				//	if PC.getPCXCoordinate == getStairX
				//	break;
				if (!stillMode) { GC.moveEnemy(); }
			}
			else if (inp == "u")
			{
				iss >> arg;
				if (checkDirection(arg))
				{
					GC.drinkPotion(string arg);
				}
				if (!stillMode) { GC.moveEnemy(); }
			}
			else if (inp == "a")
			{
				iss >> arg;
				if (checkDirection(arg)) 
				{
					GC.attackEnemy(string arg);
				}
				if (!stillMode) { GC.moveEnemy(); }
			}
			else if (inp == "f")
			{
				stillMode = 1 - stillMode;
				if (!stillMode) { GC.moveEnemy(); }
			}
			else if (inp == "r")
			{
				level = 1;
				bool stillModeOn = 0;
				GC.setLevel(0);
				break;
			}
			else if (inp == "q")
			{
				GC.displayLose();
				return 0;
			}
			GC.newboard(board.getLevel()+1);
		}
	}
	GC.displayWin();
}
