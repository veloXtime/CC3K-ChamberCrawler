#include "gameElement.h"

// Constructor
GameElement::GameElement(int x, int y, char c)
    : x{x}, y{y}, c{c} {}


// Retreive x-coordinate of the game element
int GameElement::getXCoordinate() const{
    return x;
}

// Retreive x-coordinate of the game element
int GameElement::getYCoordinate() const{
    return y;
}

void GameElement::setXCoordinate(int v){
    this->x = v;
}

void GameElement::setYCoordinate(int v){
    this->y = v;
}

// Retreive the character representing the game element on the board
char GameElement::getChar() const{
    return c;
}

// Display the game element
void GameElement::display() const{
    
}
