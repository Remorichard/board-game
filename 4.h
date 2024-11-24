#ifndef BOARD_GAMES_H
#define BOARD_GAMES_H

#include <iostream>
#include <vector>
#include <string>

// Abstract Board class
class Board {
public:
    virtual void display_board() = 0;
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_win() = 0;
    virtual bool is_draw() = 0;
    virtual bool game_is_over() = 0;
};

// Abstract Player class
class Player {
public:
    std::string name;
    char symbol;
    Player(std::string name, char symbol) : name(name), symbol(symbol) {}
    virtual void get_move(int &x, int &y) = 0;
};

// RandomPlayer class
class RandomPlayer : public Player {
public:
    RandomPlayer(std::string name, char symbol) : Player(name, symbol) {}
    void get_move(int &x, int &y) override {
        x = std::rand() % 3;
        y = std::rand() % 3;
    }
};

// GameManager class
class GameManager {
public:
    GameManager(Board *board, Player *player1, Player *player2) 
        : board(board), player1(player1), player2(player2) {}

    void run();

private:
    Board *board;
    Player *player1;
    Player *player2;
};

// Pyramid Tic-Tac-Toe
class PyramidBoard : public Board {
public:
    PyramidBoard();
    void display_board() override;
    bool update_board(int x, int y, char symbol) override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

private:
    std::vector<std::vector<char>> board;
};

class PyramidPlayer : public Player {
public:
    PyramidPlayer(std::string name, char symbol) : Player(name, symbol) {}
    void get_move(int &x, int &y) override;
};

class PyramidRandomPlayer : public RandomPlayer {
public:
    PyramidRandomPlayer(std::string name, char symbol) : RandomPlayer(name, symbol) {}
    void get_move(int &x, int &y) override;
};

// Additional game classes can be declared similarly

#endif // BOARD_GAMES_H
