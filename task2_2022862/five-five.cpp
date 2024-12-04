#include "five-five.h"

int main() {
    std::srand(std::time(0));

    // Create the 5x5 Tic Tac Toe board and players
    fiveby_fiveBoard board;
    fiveby_fivePlayer player1("Player 1", 'X');
    fiveby_fiveRandom player2("Player 2", 'O');

    // Create the game manager and start the game
    game_manager game(&board, &player1, &player2);
    game.run();

    return 0;
}
