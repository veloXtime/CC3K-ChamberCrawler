#include "display.h"
#include "potion.h"
#include "action.h"


void display::move(vector<vector<vector<shared_ptr<GameElement>>>>& b){

}

// called when the status line changes
void display::getNotified(PlayerCharacter*){

}

// called for moves, win, die
void display::action(ACTION act){
    actline += interpAction(act);
}

// append a new action message
void display::newAction(std::string s){
    actline += s;
}

// clear action string
void display::clearAction(){
    actline.clear();
}
