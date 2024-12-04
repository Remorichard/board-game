#include "pyramid.h"

int main() {
    std::srand(std::time(0));

    // Create the Pyramid Tic-Tac-Toe board and players
    Pyramid_board board;
    Pyramid_player player1("Player 1", 'X');
    Pyramid_ramdomPlayer player2("Player 2", 'O');

    // Create the game manager and start the game
    game_manager game(&board, &player1, &player2);
    game.run();

    return 0;
}
