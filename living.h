#ifndef LIVING_H
#define LIVING_H
#include <string>
#include "gameElement.h"

// abstract, no instance of Living will be created
class Living: public GameElement {
    std::string race;
    int hp,max_hp;

    protected:
        int atk,def;

    public:
        Living(int x, int y, char c, std::string race, int hp, int atk, int def, int max_hp);

        // Retreive the hp of the living object
        int getHp() const;

        // Get max hp of the living object
        int getMaxHp() const;

        // Retreive the race of the living object
        std::string getRace() const;

        // Retreive the atk of the living object
        virtual int getAtk() const;

        // Retreive the def of the living object
        virtual int getDef() const;

        // Set hp to value v
        void setHp(int v);

        // Set atk to value v
        void setAtk(int v);
        
        // Set def to value v
        void setDef(int v);
        
};

#endif
