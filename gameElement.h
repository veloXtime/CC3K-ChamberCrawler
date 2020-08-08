#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

// abstract, no instance of GameElement will be created
class GameElement 
{
    protected:
        int x, y;
        char c;


    public:
        GameElement(int x, int y, char c);
        // Retreive x-coordinate of the game element
        int getXCoordinate() const;

        // Retreive x-coordinate of the game element
        int getYCoordinate() const;

        // Retreive the character representing the game element on the board
        int getChar() const;

        // Display the game element
        void display() const;

        // Notifying its observers (virtual?)
        void notify();

        // Get notified (virtual?)
        void getNotified();
};

#endif
