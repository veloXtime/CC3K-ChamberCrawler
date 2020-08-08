#include <string>

class Potion;
class PlayerCharacter;
class Enemy;
class Treasure;

class display
{
     char board[20][80];
     std::string race, hp, atk, action; //floor is in the same line as race

    public:


        //called by a potion
        void notify(Potion *);

        //called when PC moves
        void notify(PlayerCharacter*);

        //called when Enemy moves
        void notify(Enemy*); 

        //called when a Treasure is picked up
        void notify(Treasure*); //technically we can tell what type it is by getting amount

        //combat
        void notify(PlayerCharacter*, Enemy*);
        void notify(Enemy*, PlayerCharacter*);

};