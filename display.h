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
    //These may need add an getName method or something?
    void notify(Potion *);
    void notify(PlayerCharacter*);
    void notify(Enemy*); 

    void notify(Treasure*); //technically we can tell what type it is by getting amount


};