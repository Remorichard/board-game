#include "BoardGameClasses.h"
using namespace std;


//NUMBERS OF ROWS AND COLUMNS IN BOARD;
const int ROWS = 6;
const int COLS = 7;
//Function to initialize the board;
void initializeBoard(vector<vector<char>>& Board){
  Board.assign(ROWS, vector<char>(COLS, ' '));
}

//function to display the board and column indices 
void displayBoard(const vector<vector<char>>& Board){
  for (const auto& row : Board){
    cout << " | ";
    for (char cell : row){
      cout << (cell == ' ' ? ' ' : cell)<< " | ";
    }
    cout << endl;
  }
  cout << "  0,  1,  2,  3,  4,  5,  6"<< endl;
}

//function to drop a piece into a column starting from the bottom
bool dropPiece(vector<vector<char>>& Board, int col, char piece){
  for (int row = ROWS - 1; row >= 0; --row){
    if (Board[row][col] == ' '){
      Board[row][col] = piece;
      return true;
    }
  }
  return false; //when column full
}

//function to check if a player has won, checking horizontal and vertical
bool checkWinner(const vector<vector<char>>& Board, char piece){
  for (int row = 0; row < ROWS; ++row){
    for (int col = 0; col < COLS - 3; ++col){
      if (Board[row][col] == piece && Board[row][col +1] == piece &&
       Board[row][col + 2] == piece && Board[row][col + 3] == piece){

       }
    }
  }
  for (int col = 0; col < COLS; ++col){
    for (int row = 0; row < ROWS - 3; ++row){
      if (Board[row][col] == piece && Board[row + 1][col] == piece &&
       Board[row + 2][col] == piece && Board[row + 3][col] == piece){

      }
    }
  }
  //check diagonal (\)
  for (int row = 0; row < ROWS - 3; ++row){
    for (int col = 0; col < COLS - 3; ++col){
      if (Board[row][col] == piece && Board[row + 1][col + 1] == piece &&
       Board[row + 2][col + 2] == piece && Board[row + 3][col + 3]  == piece){
        return true;
      }
    }
  }
  // check diagonal (/)
  for (int row = 3; row < ROWS; ++row){
    for (int col = 0; col < COLS - 3; ++col){
      if (Board[row][col] == piece && Board[row - 1][col + 1] == piece &&
       Board[row - 2][col + 2] == piece && Board[row- 3] [col + 3] == piece){
        return true;
      }
    }
  }
  return false;

}
// main function to run the game
int main (){
  vector <vector<char>> Board;
  initializeBoard(Board);
 // Player markers, player1 for  o, end player2 for 1
  char players[2] = {'X', 'O'};
  int turn = 0;
  while (true){
    displayBoard(Board);

    int col;
    cout << "Player "<<(turn + 1) << "(" << players[turn] << "), choose a column (0-6)";
    cin >> col;

    if (col < 0 || col >= COLS){
      cout << "Invalid column, please try again.\n";
      continue;
    }
    if (!dropPiece(Board, col, players[turn])){
      cout << "Column is full, please try again.\n";
      continue;
    }
    if (checkWinner(Board, players[turn])){
      displayBoard(Board);
      cout << "player " << (turn + 1) << "(" << players[turn] << ") win!\n";
      break;
    }
    bool isTie = true;
    for (int col = 0; col < COLS; ++col){
      if (Board[0][col] == ' '){
        isTie = false;
        break;
      }
     }
     if (isTie){
        displayBoard(Board);
        cout << "THE GAME OF TIE\n";
        break;
    }
    turn = 1 - turn;
  }
  return 0;
  
}