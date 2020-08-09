#include "architect.h"

Architect::Architect(int x, int y, char c, int ind)
: GameElement{x, y, c}, chamberInd{ind} {}

int Architect::getChamberInd() { return chamberInd; }


void Architect::getNotified(PlayerCharacter & pc)
{
	return;
}
