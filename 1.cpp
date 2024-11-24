#include "PyramidTicTacToe.h"
#include <iostream>
#include <cstdlib>

PyramidBoard::PyramidBoard() {
    board = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' '}
    };
}

void PyramidBoard::display_board() {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < board.size() - 1) std::cout << std::string(4 * (board[i].size() - 1), '-') << std::endl;
    }
}

bool PyramidBoard::update_board(int x, int y, char symbol) {
    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == ' ') {
        board[x][y] = symbol;
        return true;
    }
    return false;
}

bool PyramidBoard::is_win() {
    // Implement win checking logic
    return false; // Placeholder
}

bool PyramidBoard::is_draw() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool PyramidBoard::game_is_over() {
    return is_win() || is_draw();
}

bool PyramidBoard::check_three_in_row(int x1, int y1, int x2, int y2, int x3, int y3, char symbol) {
    // Implement checking for three in a row
    return false; // Placeholder
}

void PyramidRandomPlayer::get_move(int &x, int &y) {
    // Generate random moves within the bounds of the board
    x = std::rand() % 5;
    y = std::rand() % (5 - x);
}

