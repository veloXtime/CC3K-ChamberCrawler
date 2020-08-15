#include "scoreBoard.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Constructor
Score::Score(int score, string name)
    :score{score}, name{name} {}

int Score::getScore()
{
	return score;
}

string Score::getName()
{
	return name;
}

// clear the scoreboard
void ScoreBoard::clear(){
    score_board.clear();
}

// read in scoreboard from scoreboard.txt
void ScoreBoard::read(){
    clear();
    ifstream infile{"scoreboard.txt"};
    string line;
    while (getline(infile, line)){
		istringstream iss {line};
        int score;
        iss >> score;
        string name;
        iss >> name;
		score_board.push_back(make_shared<Score>(score,name));
	}
}

// write in new scoreboard into scoreboard.txt
void ScoreBoard::write(){
    ofstream outfile{"scoreboard.txt"};
    for (auto n : score_board) {
        outfile << n->getScore() << " " << n->getName() << endl;
    }
}

// add a score
void ScoreBoard::add(int score, string name){
    score_board.push_back(make_shared<Score>(score,name));
}

// sort score_board
void ScoreBoard::sort(){
    std::sort(score_board.begin(), score_board.end(), 
    [] (const shared_ptr<Score> & score1, const shared_ptr<Score> & score2) {
        return score1->getScore() > score2->getScore();
    });
}

// display scoreboard
void ScoreBoard::display(){
    cout << "rank    " << "score    " << "player  " << endl;
    int ctr = 1;
    sort();
    for (auto n : score_board){
        cout << left << setw(8) << ctr << left << setw(9) << n->getScore() << n->getName() << endl;
        ++ctr;
    }
}
