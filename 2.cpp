#include "FiveByFiveTicTacToe.h"
#include <iostream>
#include <cstdlib>

FiveByFiveBoard::FiveByFiveBoard() {
    board = std::vector<std::vector<char>>(5, std::vector<char>(5, ' '));
}

void FiveByFiveBoard::display_board() {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < board.size() - 1) std::cout << std::string(9, '-') << std::endl;
    }
}

bool FiveByFiveBoard::update_board(int x, int y, char symbol) {
    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == ' ') {
        board[x][y] = symbol;
        return true;
    }
    return false;
}

bool FiveByFiveBoard::is_win() {
    // Implement win checking logic
    return false; // Placeholder
}

bool FiveByFiveBoard::is_draw() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool FiveByFiveBoard::game_is_over() {
    return is_win() || is_draw();
}

bool FiveByFiveBoard::check_three_in_row(int x1, int y1, int x2, int y2, int x3, int y3, char symbol) {
    // Implement checking for three in a row
    return false; // Placeholder
}

void FiveByFiveRandomPlayer::get_move(int &x, int &y) {
    // Generate random moves within the bounds of the board
    x = std::rand() % 5;
    y = std::rand() % 5;
}
