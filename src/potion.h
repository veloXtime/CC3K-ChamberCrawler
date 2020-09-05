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
        std::string type;
        std::shared_ptr<Potion> next;
        struct visibility
        {
            bool seen[2];
        };
    public:
        Potion();
        Potion(int x, int y, int val); 
        std::string getType();
        //virtual void drink(std::shared_ptr<PlayerCharacter>);
        
        virtual std::pair<int,int> effect(); //an instance of this baseclass always return 0

        //get called when PC is nearyby
        void getNotified(PlayerCharacter&) override;
        virtual bool isSeen();

};

class PotionAtk: public Potion 
{   
    static visibility vis;
    public:
        // Costructor
        PotionAtk(int x, int y, int val);

        //void drink(PlayerCharacter*) override;
        std::pair<int,int> effect() override;
        //void getNotified(PlayerCharacter&) override;
        bool isSeen() override;
};

class PotionDef: public Potion 
{
    static visibility vis;

    public:
        // Costructor
        PotionDef(int x, int y, int val);
        
        
        std::pair<int,int> effect() override;

        //void getNotified(PlayerCharacter&) override;
        virtual bool isSeen() override;
};

class PotionHP: public Potion 
{
    static visibility vis;

    public:
        // Costructor
        PotionHP(int x, int y, int val);

        //void drink(std::shared_ptr<PlayerCharacter>) override;
        std::pair<int,int> effect() override;
        //void getNotified(PlayerCharacter&) override;
        virtual bool isSeen() override;
};

#endif
