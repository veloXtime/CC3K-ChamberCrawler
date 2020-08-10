#ifndef DWARF_H
#define DWARF_H
#include "enemyCharacter.h"

class Dwarf: public EnemyCharacter {
    public:
        // Constructor
        Dwarf(int x, int y, char c = 'W', std::string race = "dwarf", int hp = 100, int atk = 20, int def = 30, int max_hp = 100);

        // Attacked by a vampire
        virtual void attackedBy(Vampire &vampire) override;

        // Destructor
        virtual ~Dwarf();
};

#endif
