// the Game for Avoid getting three mark in the row, col, and diagonal

#include "BoardGameClasses.h"
using namespace std;

const int SIZE = 3;
//function to initalize the game board
void initializeBoard(vector<vector<char>>& Board){
  Board.assign(SIZE, vector<char>(SIZE, ' '));
}
void displayBoard(const vector<vector<char>>& Board){
  for (const auto& row : Board){
    cout << "|";
    for (char cell : row){
      cout << (cell == ' ' ? ' ' : cell) << "|";
    }
    cout << endl;
  }
  cout << endl;
}
//function to check if the current player lost
bool checklosingcondition(const vector<vector<char>>& Board, char piece){
  for (int row = 0; row < SIZE; ++row){
    if (Board[row][0] == piece && Board[row][1] == piece && Board[row][2] == piece){
      return true;
    }
  }
  for (int col = 0; col < SIZE; ++col) {
    if (Board[0][col] == piece && Board[1][col] == piece && Board[2][col] == piece){
      return true;
    } 
  }
  if (Board[0][0] == piece && Board[1][1] == piece && Board[2][2] == piece){
    return true;
  }
  if (Board[0][2] == piece && Board[1][1] == piece && Board[2][0] == piece){
    return true;
  }
  return false;
}
// main function 
int main(){
  vector<vector<char>> Board;
  initializeBoard(Board);

  char players[2] = {'X', 'O'};
  int turn = 0;
  int moves = 0;
  cout <<" Wekcome t misere tic tac toe game!:" << endl;
  cout << " Avoid getting three mark in a row, col, and diagonal" << endl;


  while(true){
    displayBoard(Board);
    int row, col;
    cout << "Player "<< (turn + 1) << "(" << players[turn] <<"), Enter you move ";
    cin >> row >> col;
    
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || Board[row][col] != ' '){
      cout << "invalid move, try again.\n";
      continue;
    }
    Board[row][col] = players[turn];
    ++moves;
    if (checklosingcondition(Board, players[turn])){
      displayBoard(Board);
      cout << "player "<< (turn + 1 ) << "(" << players[turn] << " Lose by forming three in row)" << endl;
      break;
    }
    if (moves == SIZE * SIZE){
      displayBoard(Board);
      cout << "It is a draw both players avoided forming three in a row." << endl;
      break;
    }
    turn = 1 - turn;

  }
  return 0;
}