#ifndef ARCHITECT_H
#define ARCHITECT_H
#include "gameElement.h"

class Architect: public GameElement {
	private:
		int x, y;
		char c;
	public:
		Architect(int x, int y, char c);
};

#endif
