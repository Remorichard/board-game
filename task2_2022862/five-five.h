#ifndef FIVE_BY_FIVE_TIC_TAC_TOE_H
#define FIVE_BY_FIVE_TIC_TAC_TOE_H

#include "boardgame.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
//class represent the pyramid tic tac board
class fiveby_fiveBoard: public Board{
private:
    vector <vector<char>>board; // pyramid structure of the board
    bool check3_inrow(int x1, int y1,int x2, int y2, int x3, int y3, char sym) const; 
public:
    fiveby_fiveBoard();
    void display() const override;
    bool is_validMove(int x, int y)const override;
    bool update(int x, int y, char sym) override;
    bool is_win(char sym)const override;
    bool is_draw()const override;
    int count3_inrow(char sym) const;

};

//constructor intializes the board 5X5
fiveby_fiveBoard::fiveby_fiveBoard() : Board(5){
    board = vector<vector<char>>(5, vector<char>(5, ' '));
}

void fiveby_fiveBoard:: display() const {
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout << board[i][j];
            if(j < board[i].size() - 1) cout << " | ";
        }
        cout << endl;
        if (i < board.size() - 1) cout << string(9, '-')<<endl;
    }
}


bool fiveby_fiveBoard:: is_validMove(int x, int y) const {
    return x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y] == ' ';
}

bool fiveby_fiveBoard::update(int x, int y, char sym){
    if (is_validMove(x, y)){
        board[x][y] = sym;
        return true;
    }
    return false;
}

bool fiveby_fiveBoard::is_win(char sym) const{
    //checking win .. logic based on the number of three in a row
    return count3_inrow(sym) > 0;
}

bool fiveby_fiveBoard::is_draw() const {
    for (const auto& row : board){
        for(char cell : row){
            if (cell == ' ')return false;
        }
    }
    return true;
}
int fiveby_fiveBoard::count3_inrow(char sym) const{
    int count = 0;
    //check row
    for (int i = 0; i < 5; ++i){
        for(int j = 0; j <3; ++j){
            if(check3_inrow(i, j, i, j + 1, i, j + 2, sym)) ++count;
        }
    }

    //check columns
    for(int j = 0; j < 5; ++j){
        for(int i = 0; i < 3; ++i){
            if(check3_inrow(i, j, i + 1, j, i + 2, j, sym)) ++count;
        }
    }

    //check diagonals
    for (int i = 0; i < 3; ++i){
        for(int j = 0; j <3; ++j){
            if(check3_inrow(i, j, i + 1, j + 1, i + 2, j + 2, sym)) ++count;
            if(check3_inrow(i, j + 2, i + 1, j + 1, i + 2, j, sym)) ++count;
        }
    }

    return count;
}

bool fiveby_fiveBoard::check3_inrow(int x1, int y1, int x2, int y2, int x3, int y3, char sym) const {
    return board[x1][y1] == sym && board[x2][y2] == sym && board[x3][y3] == sym;
}
class fiveby_fivePlayer : public player{
public:
    fiveby_fivePlayer(const string& name, char sym) : player(name, sym) {}
    pair<int, int> get_move(const Board& board) override;
};

pair<int, int> fiveby_fivePlayer::get_move(const Board& board){
    int x, y;
    cout <<get_name()<<", enter your move(row and column): ";
    cin>> x >> y;
    return {x, y};
}
class fiveby_fiveRandom : public random_player{
public:
   fiveby_fiveRandom(const string& name, char sym) : random_player(name, sym){}
   pair<int, int> get_move(const Board& board) override;
};
pair<int, int> fiveby_fiveRandom::get_move(const Board& board){
    int x, y;
    do{
        x = rand() % 5;
        y = rand() % (x + 1); // ensure valid position within the pyramid
    }while (!board.is_validMove(x, y));
    return {x, y};
}

#endif //FIVE_BY_FIVE_TIC_TAC_TOE_H

