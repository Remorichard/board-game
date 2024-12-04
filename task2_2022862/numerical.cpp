#include "numerical.h"

#include <ctime>


int main() {
    std::srand(std::time(0));

    // Create the Numerical Tic-Tac-Toe board and players
    Numerical_board board;
    Numerical_player player1("Player 1", '1'); // Odd numbers
    Numerical_randomplayer player2("Player 2", '2'); // Even numbers

    // Create the game manager and start the game
    game_manager game(&board, &player1, &player2);
    game.run();

    return 0;
}
