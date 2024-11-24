#ifndef NUMERICAL_TIC_TAC_TOE_H
#define NUMERICAL_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <vector>

class NumericalBoard : public Board {
public:
    NumericalBoard();
    void display_board() override;
    bool update_board(int x, int y, char symbol) override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

private:
    std::vector<std::vector<int>> board;
    bool check_sum_15(int x1, int y1, int x2, int y2, int x3, int y3);
};

class NumericalPlayer : public Player {
public:
    NumericalPlayer(std::string name, int symbol) : Player(name, symbol) {}
    void get_move(int &x, int &y) override;
};

#endif // NUMERICAL_TIC_TAC_TOE_H
