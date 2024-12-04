#include <iostream>
#include <cstdlib>
#include <ctime>

// Include game headers
#include "pyramid.h"
#include "numerical.h"
#include "four-four.h"
#include "five-five.h"


void play_game(int choice) {
    std::srand(std::time(0));

    // Create the game manager based on user choice
    if (choice == 1) {
        Pyramid_board board;
        Pyramid_player player1("Player 1", 'X');
        Pyramid_ramdomPlayer player2("Player 2", 'O');
        game_manager game(&board, &player1, &player2);
        game.run();
    }
    else if (choice == 2) {
        Numerical_board board;
        Numerical_player player1("Player 1", '1');
        Numerical_randomplayer player2("Player 2", '2');
        game_manager game(&board, &player1, &player2);
        game.run();
    }
    else if (choice == 3) {
        fourby_fourBoard board;
        fourby_fourPlayer player1("Player 1", 'X');
        fourby_fourRandom player2("Player 2", 'O');
        game_manager game(&board, &player1, &player2);
        game.run();
    }
    else if (choice == 4) {
        fiveby_fiveBoard board;
        fiveby_fivePlayer player1("Player 1", 'X');
        fiveby_fiveRandom player2("Player 2", 'O');
        game_manager game(&board, &player1, &player2);
        game.run();
    }
    else {
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
}

int main() {
    int choice;
    char play_again;

    do {
        // Display the menu
        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
        std::cout << "Select the game you want to play:" << std::endl;
        std::cout << "1. Pyramid Tic-Tac-Toe" << std::endl;
        std::cout << "2. Numerical Tic-Tac-Toe" << std::endl;
        std::cout << "3. 4x4 Tic-Tac-Toe" << std::endl;
        std::cout << "4. 5x5 Tic-Tac-Toe" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        // Start the game based on user's choice
        play_game(choice);

        // Ask if the user wants to play again
        std::cout << "Do you want to play another game? (y/n): ";
        std::cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y'); // Keep playing if user says 'y' or 'Y'

    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}
