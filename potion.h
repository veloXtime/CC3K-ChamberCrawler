#ifndef POTION_H
#define POTION_H
#include <memory>
#include "nonliving.h"
#include "playerCharacter.h"


//abstract component class, to simplify things 
//decorator and component is the same class
class Potion: public NonLiving 
{
    friend PlayerCharacter;
    protected:
        int val;
        std::shared_ptr<Potion> next;
    public:
        Potion(int x, int y, int val, std::shared_ptr<Potion>); 
        virtual void drink(PlayerCharacter*);
        
        virtual std::pair<int,int> effect(); //an instance of this baseclass always return 0

        //get called when PC is nearyby
        void getNotified(PlayerCharacter*);
};

class PotionAtk: public Potion 
{
    public:
        // Costructor
        PotionAtk(int x, int y, int val, std::shared_ptr<Potion>);

        //void drink(PlayerCharacter*) override;
        std::pair<int,int> effect() override;
};

class PotionDef: public Potion 
{
    public:
        // Costructor
        PotionDef(int x, int y, int val, std::shared_ptr<Potion>);
        

        std::pair<int,int> effect() override;
};

class PotionHP: public Potion 
{
    
    public:
        // Costructor
        PotionHP(int x, int y, int val, std::shared_ptr<Potion>);

        void drink(PlayerCharacter*) override;
        std::pair<int,int> effect() override;
};

#endif
