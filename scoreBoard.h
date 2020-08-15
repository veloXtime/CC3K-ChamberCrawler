#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H
#include <string>
#include <vector>
#include <memory>

class Score{
	private: 
		int score;
		std::string name;
    
    public:
    	// Constructor
    	Score(int score, std::string name = "anonymous");
    	int getScore();
		std::string getName();

};

class ScoreBoard{
    std::vector<std::shared_ptr<Score>> score_board;

	public:
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
