#ifndef NUMERICAL_TIC_TAC_TOE_H
#define NUMERICAL_TIC_TAC_TOE_H

#include "boardgame.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Class representing the Numerical Tic-Tac-Toe board
class Numerical_board : public Board {
private:
    vector<vector<int>> board; // 3x3 board stores integers
    bool check_sum_15(int x1, int y1, int x2, int y2, int x3, int y3) const;

public:
    Numerical_board();
    void display() const override;
    bool is_validMove(int x, int y) const override;
    bool update(int x, int y, char sym) override;
    bool is_win(char sym) const override;
    bool is_draw() const override;
};

// Constructor initializes a 3x3 board
Numerical_board::Numerical_board() : Board(3) {
    board = vector<vector<int>>(3, vector<int>(3, 0));
}

void Numerical_board::display() const {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0)
                cout << " ";
            else
                cout << board[i][j];
            if (j < board[i].size() - 1) cout << " | ";
        }
        cout << endl;
        if (i < board.size() - 1) cout << "---------\n";
    }
}

bool Numerical_board::is_validMove(int x, int y) const {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == 0;
}

bool Numerical_board::update(int x, int y, int number) {
    if (is_validMove(x, y)) {
        board[x][y] = number;
        return true;
    }
    return false;
}

bool Numerical_board::is_win(char sym) const {
    return check_sum_15(0, 0, 0, 1, 0, 2) ||
           check_sum_15(1, 0, 1, 1, 1, 2) ||
           check_sum_15(2, 0, 2, 1, 2, 2) ||
           check_sum_15(0, 0, 1, 0, 2, 0) ||
           check_sum_15(0, 1, 1, 1, 2, 1) ||
           check_sum_15(0, 2, 1, 2, 2, 2) ||
           check_sum_15(0, 0, 1, 1, 2, 2) ||
           check_sum_15(0, 2, 1, 1, 2, 0);
}

bool Numerical_board::is_draw() const {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0) return false;
        }
    }
    return !is_win('X') && !is_win('O'); // Ensure no winning condition exists
}

bool Numerical_board::check_sum_15(int x1, int y1, int x2, int y2, int x3, int y3) const {
    return board[x1][y1] + board[x2][y2] + board[x3][y3] == 15;
}

// Player class for Numerical Tic-Tac-Toe
class Numerical_player : public player {
public:
    Numerical_player(const string& name, char sym) : player(name, sym) {}
    pair<int, int> get_move(const Board& board) override;
    int get_number();

private:
    vector<int> used_numbers;
};

pair<int, int> Numerical_player::get_move(const Board& board) {
    int x, y;
    cout << get_name() << ", enter your move (row and column): ";
    cin >> x >> y;
    return {x, y};
}

int Numerical_player::get_number() {
    int number;
    while (true) {
        cout << get_name() << ", enter your number: ";
        cin >> number;
        if ((sym == 'X' && number % 2 == 1) || (sym == 'O' && number % 2 == 0)) {
            if (find(used_numbers.begin(), used_numbers.end(), number) == used_numbers.end()) {
                used_numbers.push_back(number);
                return number;
            }
        }
        cout << "Invalid or already used number, try again.\n";
    }
}

// Random Player Class
class Numerical_randomplayer : public random_player {
public:
    Numerical_randomplayer(const string& name, char sym) : random_player(name, sym) {}
    pair<int, int> get_move(const Board& board) override;
    int get_number();

private:
    vector<int> used_numbers;
};

pair<int, int> Numerical_randomplayer::get_move(const Board& board) {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (!board.is_validMove(x, y));
    return {x, y};
}

int Numerical_randomplayer::get_number() {
    int number;
    while (true) {
        number = (sym == 'X') ? (rand() % 5) * 2 + 1 : (rand() % 4 + 1) * 2;
        if (find(used_numbers.begin(), used_numbers.end(), number) == used_numbers.end()) {
            used_numbers.push_back(number);
            return number;
        }
    }
};

#endif // NUMERICAL_TIC_TAC_TOE_H
