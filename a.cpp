#include <iostream>
#include <vector>

class PyramidTicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    PyramidTicTacToe() : board(3), currentPlayer('X') {
        board[0] = {' ', ' ', ' '};
        board[1] = {' ', ' ', ' ', ' '};
        board[2] = {' ', ' '};
    }

    void displayBoard() {
        std::cout << "  0 1 2 3 4\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i << " ";
            for (int j = 0; j < board[i].size(); ++j) {
                std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= board[row].size() || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check horizontal and vertical
        for (int i = 0; i < 3; ++i) {
            if (checkLine(board[i][0], board[i][1], board[i][2]) || 
                (i < 2 && checkLine(board[i][0], board[i][3], board[i][4]))) {
                return true;
            }
        }
        // Check diagonal
        return checkLine(board[0][0], board[1][1], board[2][0]) || 
               checkLine(board[0][2], board[1][1], board[2][1]);
    }

    bool checkLine(char a, char b, char c) {
        return (a == b && b == c && a != ' ');
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                switchPlayer();
            } else {
                std::cout << "Invalid move, try again.\n";
            }
        }
    }
};

int main() {
    PyramidTicTacToe game;
    game.playGame();
    return 0;
}
