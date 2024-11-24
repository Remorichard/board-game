#ifndef PYRAMID_TIC_TAC_TOE_H
#define PYRAMID_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <vector>

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
    bool check_three_in_row(int x1, int y1, int x2, int y2, int x3, int y3, char symbol);
};

class PyramidPlayer : public Player {
public:
    PyramidPlayer(std::string name, char symbol) : Player(name, symbol) {}
};

class PyramidRandomPlayer : public RandomPlayer {
public:
    PyramidRandomPlayer(std::string name, char symbol) : RandomPlayer(name, symbol) {}
    void get_move(int &x, int &y) override;
};

#endif // PYRAMID_TIC_TAC_TOE_H
