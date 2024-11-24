#include "NumericalTicTacToe.h"
#include <iostream>
#include <cstdlib>

NumericalBoard::NumericalBoard() {
    board = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
}

void NumericalBoard::display_board() {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < board.size() - 1) std::cout << std::string(5, '-') << std::endl;
    }
}

bool NumericalBoard::update_board(int x, int y, char symbol) {
    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == 0[_{{{CITATION{{{_1{](https://github.com/blizzaaard/lc2015/tree/471134aae9e4ef8b48754223a1e8584759f55634/sudoku_solver.cpp)