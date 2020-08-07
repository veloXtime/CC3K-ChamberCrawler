#ifndef ARCHITECT_H
#define ARCHITECT_H
#include "gameElement.h"

class Architect: public GameElement {
	private:
		int x, y;
		char c;
		int chamberInd;
	public:
		Architect(int x, int y, int chamberInd, char c);
		int getChamberInd();
};

#endif
