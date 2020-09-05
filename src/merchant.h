#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyCharacter.h"

class Merchant: public EnemyCharacter {
    static bool hostile;

    public:
        // Constructor
        Merchant(int x, int y, char c = 'M', std::string race = "merchant", int hp = 30, int atk = 70, int def = 5, int max_hp = 30);

        // If any merchant has been attacked
        bool getHostile();

        // Upon death of an enemy slained by pc
        virtual void death(PlayerCharacter &pc) override;

        // Override notify
        virtual void getNotified(PlayerCharacter &pc) override;

        // Destructor
        virtual ~Merchant();

        // Attacked by a shade
        virtual void attackedBy(Shade &shade) override;

        // Attacked by a drow
        virtual void attackedBy(Drow &drow) override;

        // Attacked by a vampire
        virtual void attackedBy(Vampire &vampire) override;

        // Attacked by a troll
        virtual void attackedBy(Troll &troll) override;

        // Attacked by a goblin
        virtual void attackedBy(Goblin &goblin) override;
};

#endif
