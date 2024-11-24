#ifndef PYRAMID_TICTACTOE_H
#define PYRAMID_TICTACTOE_H

#include "boardgame.h"

// Pyramid_Board class
class Pyramid_Board : public Board {
private:
    vector<vector<char>> board; // Pyramid board
    const vector<size_t> row_sizes = {5, 3, 1}; // Row sizes of the pyramid
    int total_moves = 0; // To track the number of moves made

public:
    Pyramid_Board() : board(3) {
        for (size_t i = 0; i < row_sizes.size(); ++i) {
            board[i] = vector<char>(row_sizes[i], ' '); // Initialize empty board
        }
    }

    bool is_validMove(int x, int y) const override {
        if (x < 0 || x >= 3 || y < 0 || y >= row_sizes[x]) return false;
        return board[x][y] == ' ';
    }

    bool update(int x, int y, char sym) override {
        if (is_validMove(x, y)) {
            board[x][y] = sym;
            total_moves++;
            return true;
        }
        return false;
    }

    bool is_win(char sym) const override {
        // Horizontal check
        for (size_t i = 0; i < board.size(); ++i) {
            if (row_sizes[i] >= 3) {
                for (int j = 0; j <= row_sizes[i] - 3; ++j) {
                    if (board[i][j] == sym && board[i][j + 1] == sym && board[i][j + 2] == sym) {
                        return true;
                    }
                }
            }
        }

        // Vertical check
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < row_sizes[i]; ++j) {
                if (j < row_sizes[i + 1] && board[i][j] == sym && board[i + 1][j] == sym &&
                    (i + 2 < 3 && board[i + 2][0] == sym)) {
                    return true;
                }
            }
        }

        // Diagonal check (specific to pyramid)
        if (board[0][0] == sym && board[1][1] == sym && board[2][0] == sym) return true;
        if (board[0][4] == sym && board[1][1] == sym && board[2][0] == sym) return true;

        return false;
    }

    bool is_draw() const override {
        return total_moves == 9; // Pyramid has 9 total squares
    }

    void display() const override {
        cout << "Pyramid Tic-Tac-Toe Board:\n";
        for (size_t i = 0; i < board.size(); ++i) {
            for (int j = 0; j < row_sizes[i] - i; ++j) cout << " "; // Indentation for pyramid shape
            for (size_t j = 0; j < board[i].size(); ++j) {
                cout << (board[i][j] == ' ' ? '.' : board[i][j]) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Custom Pyramid Player
class Pyramid_Player : public player {
public:
    Pyramid_Player(const string& name, char sym) : player(name, sym) {}

    pair<int, int> get_move(const Board& board) override {
        int x, y;
        cout << name << ", enter your move (row and column): ";
        cin >> x >> y;
        return {x, y};
    }
};

#endif
