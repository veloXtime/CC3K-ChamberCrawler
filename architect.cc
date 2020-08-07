#include "architect.h"

Architect::Architect(int x, int y, char c, int ind) : x{x}, y{y}, c{c}, chamberInd{ind} {}

int Architect::getChamberInd() { return chamberInd; }
