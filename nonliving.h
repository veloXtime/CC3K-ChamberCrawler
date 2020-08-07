#ifndef NON_LIVING_H
#define NON_LIVING_H
#include "gameElement.h"

// abstract, no instance of NonLiving will be created
class NonLiving: public GameElement {
    public:
        NonLiving(int, int, char);
};

#endif
