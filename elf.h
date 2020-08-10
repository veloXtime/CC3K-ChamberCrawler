#ifndef ELF_H
#define ELF_H
#include "enemyCharacter.h"

class Elf: public EnemyCharacter {
    public:
        // Constructor
        Elf(int x, int y, char c = 'E', std::string race = "elf", int hp = 140, int atk = 30, int def = 10, int max_hp = 140);

        // Destructor
        ~Elf();
};

#endif
