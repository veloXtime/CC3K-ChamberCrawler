#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

// abstract, no instance of GameElement will be created
class GameElement {
    int x, y;
    char c;


    public:
        // Retreive x-coordinate of the game element
        int getXCoordinate() const;

        // Retreive x-coordinate of the game element
        int getYCoordinate() const;

        // ???
        int getChar() const;

        // Display the game element
        void display() const;

        // Notifying its observers (virtual?)
        void notify();

        // Get notified (virtual?)
        void getNotified();
};

#endif
