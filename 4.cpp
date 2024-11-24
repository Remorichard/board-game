#include "4.h"
#include <cstdlib>
#include <ctime>

// GameManager implementation
void GameManager::run() {
    int x, y;
    Player *players[] = {player1, player2};
    int currentPlayer = 0;

    board->display_board();
    while (!board->game_is_over()) {
        players[currentPlayer]->get_move(x, y);
        while (!board->update_board(x, y, players[currentPlayer]->symbol)) {
            std::cout << "Invalid move. Try again." << std::endl;
            players[currentPlayer]->get_move(x, y);
        }
        board->display_board();
        if (board->is_win()) {
            std::cout << players[currentPlayer]->name << " wins!" << std::endl;
            return;
        }
        if (board->is_draw()) {
            std::cout << "Draw!" << std::endl;
            return;
        }
        currentPlayer = 1 - currentPlayer; // Swap players
    }
}

// Pyramid Tic-Tac-Toe implementation
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

void PyramidPlayer::get_move(int &x, int &y) {
    std::cout << "Enter move for " << name << " (level, position): ";
    std::cin >> x >> y;
}

void PyramidRandomPlayer::get_move(int &x, int &y) {
    x = std::rand() % 5;
    y = std::rand() % (5 - x);
}

// Additional game implementations can be similarly added

int main() {
    std::srand(std::time(0));

    // Example usage for Pyramid Tic-Tac-Toe
    PyramidBoard board;
    PyramidPlayer player1("Player 1", 'X');
    PyramidRandomPlayer player2("Player 2", 'O');
    GameManager game(&board, &player1, &player2);
    game.run();

    return 0;
}
