#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;
//board class abstract
class Board {
protected:
    int board_size;
public:
    Board(int size) : board_size(size) {}
    virtual bool is_validMove(int x, int y) const =  0;
    virtual bool update(int x,int y, char sym) = 0;
    virtual bool is_win(char sym) const = 0;
    virtual bool is_draw() const = 0;
    virtual void display() const= 0;
    virtual ~Board() = default;
};

//player generic class
class player{
protected:
   string name;
   char sym;

public:
  player(const string& name, char sym) : name(name), sym(sym){}
  virtual pair<int, int> get_move(const Board& board) = 0;
  string get_name() const {return name;}
  char get_sym() const {return sym;}

  virtual ~player() = default;
};

// random player generates random moves
class random_player : public player {
public:
    random_player(const string& name, char sym) : player(name, sym) {
        srand(time(0));
    }

    pair<int, int> get_move(const Board& board) override{
        int x, y;
        do {
            x = rand() % 5;
            y = rand() % 5;
        } while(!board.is_validMove(x, y));
        return {x, y};
    }
};

//game manager

class game_manager {
private:
    Board* board;
    player* Player[2];

public:
    game_manager(Board* board, player* p1, player* p2) : board(board){
        Player[0] = p1;
        Player[1] = p2;
    }

    void run(){
        int turn = 0;
        board ->display();

        while(true){
            player* current_player = Player[turn];
            cout<< current_player->get_name()<<"'s turn ("<<current_player->get_sym() << "):\n";
            int x, y;
            while(true){
                auto move = current_player->get_move(*board);
                x = move.first;
                y = move.second;
                if(board -> update(x, y, current_player->get_sym())) break;
                cout << "Invalid move, try again.\n";
            }
            board -> display();
            if(board -> is_win(current_player->get_sym())){
                cout << current_player->get_name() << " wins!\n";
                return;
            }
            if(board -> is_draw()){
                cout << "It's a draw!\n";
                return;
            }
            turn = (turn + 1) % 2;
        }
    }
};

// In boardgame_classes.h
class HumanPlayer : public player {
public:
    HumanPlayer(const string& name, char sym) : player(name, sym) {}

    pair<int, int> get_move(const Board& board) override {
        int x, y;
        cout << get_name() << ", enter your move (row and column): ";
        cin >> x >> y;
        return {x, y};
    }
};


#endif