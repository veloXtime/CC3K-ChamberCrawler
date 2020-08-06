#ifndef LIVING_H
#define LIVING_H
#include <string>
#include "gameElement.h"

class Living: public gameElement {
    std::string race;
    int hp,atk,def,max_hp;
    char c;

    public:
        // Retreive the hp of the living object
        int getHp() const;
        
        // Set hp to value v
        void setHp(int v);

        // Get max hp of the living object
        int getMaxHp() const;

        // Retreive the atk of the living object
        int getAtk() const;
        
        // Set atk to value v
        void setAtk(int v);

        // Retreive the def of the living object
        int getDef() const;
        
        // Set def to value v
        void setDef(int v);
        
        // Retreive the race of the living object
        std::string getRace() const;

        // Notifying its observers
        void notify();

};

#endif
