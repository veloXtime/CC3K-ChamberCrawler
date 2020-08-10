#include <string>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::vector;

class GameElement;
class Potion;
class PlayerCharacter;
class Enemy;
class Treasure;


enum class ACTION{};
class display
{
    //char board[20][80];
    std::string status, hp, atk, action; //floor is in the same line as race
    
    
    public:

        void move(vector<vector<vector<shared_ptr<GameElement>>>>);

        //called when the status line changes
        void notify(PlayerCharacter*);


        void action(ACTION);
        void action(ACTION, int, PlayerCharacter*, Enemy*);
        void action(ACTION, int, Enemy*, PlayerCharacter*);

};