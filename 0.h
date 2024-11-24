#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H

#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// Abstract Board Class
class Board {
public:
    virtual void display() const = 0;
    virtual bool update(int x, int y, char symbol) = 0;
    virtual bool isWin(char symbol) const = 0;
    virtual bool isDraw() const = 0;
    virtual bool isValidMove(int x, int y) const = 0;
    virtual ~Board() = default;
};

// Generic Player Class
class Player {
protected:
    string name;
    char symbol;

public:
    Player(string name, char symbol) : name(name), symbol(symbol) {}
    virtual pair<int, int> getMove(const Board& board) = 0;
    string getName() const { return name; }
    char getSymbol() const { return symbol; }
    virtual ~Player() = default;
};

// Random Player (inherits Player)
class RandomPlayer : public Player {
public:
    RandomPlayer(string name, char symbol) : Player(name, symbol) {}

    pair<int, int> getMove(const Board& board) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 4); // Assuming a 5x5 grid for demo
        int x, y;
        do {
            x = dis(gen);
            y = dis(gen);
        } while (!board.isValidMove(x, y));
        return {x, y};
    }
};

// GameManager Class
class GameManager {
private:
    Board* board;
    Player* players[2];
    int currentPlayerIndex;

public:
    GameManager(Board* board, Player* p1, Player* p2) 
        : board(board), currentPlayerIndex(0) {
        players[0] = p1;
        players[1] = p2;
    }

    void run() {
        board->display();
        while (true) {
            Player* currentPlayer = players[currentPlayerIndex];
            cout << currentPlayer->getName() << "'s turn (" << currentPlayer->getSymbol() << "):\n";
            auto [x, y] = currentPlayer->getMove(*board);

            if (board->update(x, y, currentPlayer->getSymbol())) {
                board->display();

                if (board->isWin(currentPlayer->getSymbol())) {
                    cout << currentPlayer->getName() << " wins!\n";
                    return;
                }
                if (board->isDraw()) {
                    cout << "It's a draw!\n";
                    return;
                }

                currentPlayerIndex = 1 - currentPlayerIndex; // Switch turns
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
    }
};

#endif // BOARDGAME_CLASSES_H
