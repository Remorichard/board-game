#include "BoardGameClasses.h";
using namespace std;

const int SIZE = 9;
char board[SIZE][SIZE];
char mainBoard[3][3];

void initializeBoard() {
  for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
          board[i][j] = ' ';
  for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
          mainBoard[i][j] = ' ';
}

void printBoard() {
    for(int i = 0; i < SIZE; ++i) {
      for(int j = 0; j < SIZE; ++j) {
        cout << "| " << board[i][j] << " ";
        if(j % 3 == 2) cout << "| ";
    }
    cout << "\n";
    if(i % 3 == 2) {
      for(int k = 0; k < SIZE; ++k)
          cout << "---";
      cout << "\n";
    }
  }
  cout << "Main Board:\n";
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      cout << "| " << mainBoard[i][j] << " ";
    }
    cout << "|\n";
  }
}

bool isValidMove(int row, int col) {
  return board[row][col] == ' ';
}

void placeMark(int row, int col, char mark) {
  board[row][col] = mark;
  // Update main board if a smaller board is won
}

bool checkWin(char mark, char b[3][3]) {
  // Check rows, columns, and diagonals on a 3x2 board
  for(int i = 0; i < 3; ++i)
      if(b[i][0] == mark && b[i][1] == mark && b[i][2] == mark) 
        return true;
  for(int i = 0; i < 3; ++i)
      if(b[0][i] == mark && b[1][i] == mark && b[2][i] == mark)
          return true;
  if(b[0][0] == mark && b[1][1] == mark && b[2][2] == mark)
      return true;
  if(b[0][2] == mark && b[1][1] == mark && b[2][0] == mark)
      return true;
  return false;
      
}

int main() {
  initializeBoard();
  printBoard();
  char currentPlayer = 'X';
  while(true) {
    int row, col;
    cout << "Player " << currentPlayer << ", enter row (1-9) and column (1-9): ";
    cin >> row >> col;
    row--; col--; // Adjust for 0-based index

    if(isValidMove(row, col)) {
      placeMark(row, col, currentPlayer);
      printBoard();
      int smallRow = row / 3;
      int smallCol = col / 3;
      char smallBoard[3][3];
      // Extract the smaller board
      for(int i = 0; i < 3; ++i)
          for(int j = 0; j < 3; ++j)
            smallBoard[i][j] = board[smallRow * 3 + 1][smallCol * 3 + 1];
      if(checkWin(currentPlayer, smallBoard)) {
          mainBoard[smallRow][smallCol] = currentPlayer;
          cout << "Player " << currentPlayer << " wins small board at (" << (smallRow+1) << "," << (smallCol+1) << ")!\n" ;
            if(checkWin(currentPlayer, mainBoard)) {
              cout << "Player " << currentPlayer << " wins the ultimate Tic Tic Toe game\n";
              break;
            }
        }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } else {
      cout << "Invalid move. Try again.\n";
    }
  } 
  return 0;
}