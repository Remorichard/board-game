#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Board class abstract
class Board {
protected:
    int board_size;
public:
    Board(int size) : board_size(size) {}
    virtual bool is_validMove(int x, int y) const =  0;
    virtual bool update(int x, int y, char sym) = 0;
    virtual bool is_win(char sym) const = 0;
    virtual bool is_draw() const = 0;
    virtual void display() const = 0;
    virtual ~Board() = default;
};

// Player generic class
class player {
protected:
    string name;
    char sym;

public:
    player(const string& name, char sym) : name(name), sym(sym) {}
    virtual pair<int, int> get_move(const Board& board) = 0;
    string get_name() const { return name; }
    char get_sym() const { return sym; }

    virtual ~player() = default;
};

// Human player enters moves manually
class human_player : public player {
public:
    human_player(const string& name, char sym) : player(name, sym) {}

    pair<int, int> get_move(const Board& board) override {
        int x, y;
        while (true) {
            cout << "Enter the column (0-6) where you want to drop your " << sym << ":\n";
            cin >> x;

            if (x < 0 || x > 6) {
                cout << "Invalid column number. Please enter a value between 0 and 6.\n";
                continue;
            }

            y = 0;
            // Find the lowest available row in the selected column
            while (y < 6 && !board.is_validMove(x, y)) {
                y++;
            }

            if (y < 6) {
                break;  // Valid move found
            } else {
                cout << "Column " << x << " is full. Try another column.\n";
            }
        }
        return {x, y};
    }
};

// ConnectFourBoard class implementation
class ConnectFourBoard : public Board {
private:
    vector<vector<char>> grid;

public:
    ConnectFourBoard() : Board(7), grid(6, vector<char>(7, ' ')) {}

    bool is_validMove(int x, int y) const override {
        return x >= 0 && x < 7 && y >= 0 && y < 6 && grid[y][x] == ' ';
    }

    bool update(int x, int y, char sym) override {
        if (is_validMove(x, y)) {
            grid[y][x] = sym;
            return true;
        }
        return false;
    }

    bool is_win(char sym) const override {
        // Check for horizontal, vertical, and diagonal win
        for (int y = 0; y < 6; y++) {
            for (int x = 0; x < 7; x++) {
                if (grid[y][x] == sym) {
                    // Horizontal check
                    if (x + 3 < 7 && grid[y][x + 1] == sym && grid[y][x + 2] == sym && grid[y][x + 3] == sym)
                        return true;
                    // Vertical check
                    if (y + 3 < 6 && grid[y + 1][x] == sym && grid[y + 2][x] == sym && grid[y + 3][x] == sym)
                        return true;
                    // Diagonal check (bottom-left to top-right)
                    if (x + 3 < 7 && y + 3 < 6 && grid[y + 1][x + 1] == sym && grid[y + 2][x + 2] == sym && grid[y + 3][x + 3] == sym)
                        return true;
                    // Diagonal check (bottom-right to top-left)
                    if (x - 3 >= 0 && y + 3 < 6 && grid[y + 1][x - 1] == sym && grid[y + 2][x - 2] == sym && grid[y + 3][x - 3] == sym)
                        return true;
                }
            }
        }
        return false;
    }

    bool is_draw() const override {
        for (int y = 0; y < 6; y++) {
            for (int x = 0; x < 7; x++) {
                if (grid[y][x] == ' ')
                    return false;
            }
        }
        return true;
    }

    void display() const override {
        for (int y = 0; y < 6; y++) {
            cout << "|";  // Start the row with a vertical bar
            for (int x = 0; x < 7; x++) {
                cout << grid[y][x] << "|";  // Print each cell with a vertical bar
            }
            cout << endl;  // Move to the next line after each row
        }
    }
};

// Game manager
class game_manager {
private:
    Board* board;
    player* Player[2];

public:
    game_manager(Board* board, player* p1, player* p2) : board(board) {
        Player[0] = p1;
        Player[1] = p2;
    }

    void run() {
        int turn = 0;
        board->display();

        while (true) {
            player* current_player = Player[turn];
            cout << current_player->get_name() << "'s turn (" << current_player->get_sym() << "):\n";
            int x, y;
            while (true) {
                auto move = current_player->get_move(*board);
                x = move.first;
                y = move.second;
                if (board->update(x, y, current_player->get_sym())) break;
                cout << "Invalid move, try again.\n";
            }
            board->display();
            if (board->is_win(current_player->get_sym())) {
                cout << current_player->get_name() << " wins!\n";
                return;
            }
            if (board->is_draw()) {
                cout << "It's a draw!\n";
                return;
            }
            turn = (turn + 1) % 2;
        }
    }
};

#endif
