#ifndef ARCHITECT_H
#define ARCHITECT_H
#include "gameElement.h"

class Architect: public GameElement {
	private:
		int chamberInd;
	public:
		Architect(int x, int y, char c, int chamberInd);
		int getChamberInd();
};

#endif
