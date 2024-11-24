#include "z.h"

int main() {
    // Create the pyramid board
    Pyramid_Board Pyramid_board;

    // Create players
    Pyramid_Player player1("Player 1", 'X');
    Pyramid_Player player2("Player 2", 'O');

    // Create game manager
    game_manager pyramid_game(&Pyramid_board, &player1, &player2);

    // Run the game
    pyramid_game.run();

    return 0;
}
