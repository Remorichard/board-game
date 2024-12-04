#ifndef FOUR_BY_FOUR_TIC_TAC_TOE_H
#define FOUR_BY_FOUR_TIC_TAC_TOE_H

#include "boardgame.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
class fourby_fourBoard: public Board{
private:
    vector <vector<char>>board; // pyramid structure of the board
    bool check3_inrow(int x1, int y1,int x2, int y2, int x3, int y3, char sym) const;
    bool is_adjacentMove(int x1, int y1, int x2, int y2) const;
public:
    fourby_fourBoard();
    void display() const override;
    bool is_validMove(int x, int y)const override;
    bool update(int x, int y, char sym) override;
    bool is_win(char sym)const override;
    bool is_draw()const override;

};

fourby_fourBoard::fourby_fourBoard() : Board(4){
    board = vector<vector<char>>(4, vector<char>(4, ' '));
    board = {
        {'X', 'O', 'X', 'O'},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {'0', 'X', 'O', 'X'}
    };
}

void fourby_fourBoard::display() const{
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout<<board[i][j];
            if(j < board[i].size() - 1) cout << " | ";
        }
        cout << endl;
        if (i < board.size() - 1) cout << "----------\n"<<endl;
    }
}

bool fourby_fourBoard:: is_validMove(int x, int y) const {
    return x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == ' ';
}

bool fourby_fourBoard:: update(int x, int y, char sym){
    int curr_x = -1, curr_y = -1;
    for(int i =0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            if(board[i][j] == sym){
                curr_x = i;
                curr_y = j;
                break;
            }
        }
        if(curr_x != -1) break;
    }

    if(is_validMove(x, y) && is_adjacentMove(curr_x, curr_y, x, y)){
        board[curr_x][curr_y] = ' '; //clear the old position
        board[x][y] = sym;//place the token in the  new position
        return true;
    }
    return false;
}

bool fourby_fourBoard::is_win(char sym) const{
    // check for mwinnig conditions in 4x4 
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j <2; ++j){
            if (check3_inrow(i, j, i, j + 1, i, j + 2, sym)) return true;
            if(check3_inrow(j, i, j + 1, i, j + 2, i, sym)) return true;
        }
    }
    return check3_inrow(0, 0, 1, 1, 2, 2, sym)||
           check3_inrow(0, 2, 1, 1, 2, 0, sym)||
           check3_inrow(1, 0, 2, 1, 3, 2, sym)||
           check3_inrow(1, 3, 2, 2, 3, 1, sym);
}

bool fourby_fourBoard::is_draw() const {
    for (const auto& row : board){
        for(char cell : row){
            if (cell == ' ')return false;
        }
    }
    return true;
}

bool fourby_fourBoard::check3_inrow(int x1, int y1, int x2, int y2, int x3, int y3, char sym) const {
    return board[x1][y1] == sym && board[x2][y2] == sym && board[x3][y3] == sym;
}

bool fourby_fourBoard ::is_adjacentMove(int x1, int y1, int x2, int y2) const{
    return (abs(x1 - x2) == 1 && y1 == y2) || (abs(y1 - y2) == 1 && x1 == x2);
}

class fourby_fourPlayer : public player{
public:
    fourby_fourPlayer(const string& name, char sym) : player(name, sym) {}
    pair<int, int> get_move(const Board& board) override;
};

pair<int, int> fourby_fourPlayer::get_move(const Board& board){
    int x, y;
    cout <<get_name()<<", enter your move(row and column): ";
    cin>> x >> y;
    return {x, y};
}

class fourby_fourRandom : public random_player{
public:
   fourby_fourRandom(const string& name, char sym) : random_player(name, sym){}
   pair<int, int> get_move(const Board& board) override;
};

pair<int, int> fourby_fourRandom::get_move(const Board& board){
    int x, y;
    do{
        x = rand() % 4;
        y = rand() % 4; 
    }while (!board.is_validMove(x, y));
    return {x, y};
}

#endif // FOUR_BY_FOUR_TIC_TAC_TOE_H
