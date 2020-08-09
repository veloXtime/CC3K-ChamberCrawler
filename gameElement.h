#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

class PlayerCharacter;

// abstract, no instance of GameElement will be created
class GameElement 
{
    protected:
        int x, y;
        char c;

    public:
        // Constructor
        GameElement(int x, int y, char c);

        // Retreive x-coordinate of the game element
        int getXCoordinate() const;

        // Retreive x-coordinate of the game element
        int getYCoordinate() const;

        void setXCoordinate(int x);

        void setYCoordinate(int y);

        // Retreive the character representing the game element on the board
        char getChar() const;

        // Display the game element
        void display() const;

        // Get notified (virtual?)
        virtual void getNotified(PlayerCharacter & pc) = 0;
};

#endif
