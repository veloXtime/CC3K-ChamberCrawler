#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H
#include <string>
#include <vector>
#include <memory>

struct Score{
    int score;
    std::string name;
    
    // Constructor
    Score(int score, std::string name = "anonymous");
};

struct ScoreBoard{
    std::vector<std::shared_ptr<Score>> score_board;

    // clear the scoreboard
    void clear();
    
    // read in scoreboard from scoreboard.txt
    void read();

    // write in new scoreboard into scoreboard.txt
    void write();

    // add a score
    void add(int score, std::string name);

    // sort score_board
    void sort();

    // display scoreboard
    void display();
    
};

#endif
