#ifndef PYRAMID_TIC_TAC_TOE_H
#define PYRAMID_TIC_TAC_TOE_H

#include "boardgame.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//class represent the pyramid tic tac board
class Pyramid_board: public Board{
private:
    vector <vector<char>>board; // pyramid structure of the board
    bool check3_inrow(int x1, int y1,int x2, int y2, int x3, int y3, char sym) const; 
public:
    Pyramid_board();
    void display() const override;
    bool is_validMove(int x, int y)const override;
    bool update(int x, int y, char sym) override;
    bool is_win(char sym)const override;
    bool is_draw()const override;

};

// class representing a huyman  player in pyramid tic tac toe
class Pyramid_player : public player{
public:
    Pyramid_player(const string& name, char sym) : player(name, sym) {}
    pair<int, int> get_move(const Board& board) override;
};

//class for a random a1 player in pyramid 
class Pyramid_ramdomPlayer : public random_player{
public:
   Pyramid_ramdomPlayer(const string& name, char sym) : random_player(name, sym){}
   pair<int, int> get_move(const Board& board) override;
};

//Implementation of pyramid board methods
Pyramid_board::Pyramid_board() : Board(5){
    board = {
        {' '},
        {' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };
}

void Pyramid_board:: display() const {
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout << board[i][j];
            if(j < board[i].size() - 1) cout << " | ";
        }
        cout << endl;
        if (i < board.size() - 1) cout << string(4 * (board[i].size() - 1), '-')<<endl;
    }
}

bool Pyramid_board:: is_validMove(int x, int y) const {
    return x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y] == ' ';
}

bool Pyramid_board::update(int x, int y, char sym){
    if (is_validMove(x, y)){
        board[x][y] = sym;
        return true;
    }
    return false;
}

bool Pyramid_board::is_win(char sym) const {
    //check for win conditions in pyramid 
    return check3_inrow(0, 0, 1, 1, 2, 2, sym) ||
           check3_inrow(0, 1, 1, 2, 2, 3, sym) ||
           check3_inrow(1, 0, 2, 1, 3, 2, sym) ||
           check3_inrow(1, 1, 2, 2, 3, 3, sym) ||
           check3_inrow(2, 0, 3, 1, 4, 2, sym) ||
           check3_inrow(2, 1, 3, 2, 4, 3, sym) ||
           check3_inrow(2, 2, 3, 3, 4, 4, sym);
}

bool Pyramid_board::is_draw() const {
    for (const auto& row : board){
        for(char cell : row){
            if (cell == ' ')return false;
        }
    }
    return true;
}

bool Pyramid_board::check3_inrow(int x1, int y1, int x2, int y2, int x3, int y3, char sym) const {
    return board[x1][y1] == sym && board[x2][x2] == sym && board[x3][y3] == sym;
}

//pyramid player methods
pair<int, int> Pyramid_player::get_move(const Board& board){
    int x, y;
    cout <<get_name()<<", enter your move(level and position): ";
    cin>> x >> y;
    return {x, y};
}

// implemntation of pyramid random player methhods
pair<int, int> Pyramid_ramdomPlayer::get_move(const Board& board){
    int x, y;
    do{
        x = rand() % 5;
        y = rand() % (x + 1); // ensure valid position within the pyramid
    }while (!board.is_validMove(x, y));
    return {x, y};
}
#endif // PYRAMID_TIC_TAC_TOE_H

