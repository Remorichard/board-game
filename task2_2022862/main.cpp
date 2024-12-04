#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pyramid.h"
#include "numerical.h"
#include "four-four.h"
#include "five-five.h"

using namespace std;

void pyramidTic_tacToe(){
    srand(time(0));
    Pyramid_board board;
    Pyramid_player player1("Player 1", 'X');
    Pyramid_ramdomPlayer player2("Player 2", 'O');
    game_manager game(&board, &player1, &player2);
    game.run();
}

void NumericTic_tacToe(){
    srand(time(0));
    Numerical_board board;
    Numerical_player player1("Player 1", '1');
    Numerical_randomplayer player2("Player 2", '2');
    game_manager game(&board, &player1, &player2);
    game.run();

}

void fourbyfourTic_toe(){
    srand(time(0));
    fourby_fourBoard board;
    fourby_fourPlayer player1("Player 1", 'X');
    fourby_fourRandom player2("Player 2", 'O');
    game_manager game(&board, &player1, &player2);
    game.run();
}

void fivebyfive_toe(){
    srand(time(0));
    fiveby_fiveBoard board;
    fiveby_fivePlayer player1("Player 1", 'X');
    fiveby_fiveRandom player2("Player 2", 'O');
    game_manager game(&board, &player1, &player2);
    game.run();
}

int main(){
    int choice;
    do{
        cout << "Choose a game: " << endl;
        cout << "1. Pyramid Tic Tac Toe" << endl;
        cout << "2. Numerical Tic Tac Toe" << endl;
        cout << "3. Four by Four Tic Tac Toe" << endl;
        cout << "4. Five by Five Tic Tac Toe" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice){
            case 1:
                pyramidTic_tacToe();
                break;
            case 2:
                NumericTic_tacToe();
                break;
            case 3:
                fourbyfourTic_toe();
                break;
            case 4:
                fivebyfive_toe();
                break;
            case 5:
                cout << "Thanks you for playiing Goodbye!\n" << endl;
                break;
            default:
                cout<<"invalid choice please try again.\n";
        }
        if (choice != 5){
            cout << "would you like to  play another again? (1 for Yes, n for 0): ";
            int response;
            cin >> response;
            if (!response){
                cout<<"Thank you for playing! Goodbye!\n";
                break;
            }    
        }
    }while (choice != 5);
    
}
