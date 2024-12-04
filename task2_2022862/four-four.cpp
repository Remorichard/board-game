#include "four-four.h"

int main() {
    std::srand(std::time(0));

    // Create the 4x4 Tic Tac Toe board and players
    fourby_fourBoard board;
    fourby_fourPlayer player1("Player 1", 'X');
    fourby_fourRandom player2("Player 2", 'O');

    // Create the game manager and start the game
    game_manager game(&board, &player1, &player2);
    game.run();

    return 0;
}
