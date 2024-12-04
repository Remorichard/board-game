#include "BoardGameClasses.h"
using namespace std;

const int SIZE = 3;
//function to load volid works from dicuments
unordered_set<string> loadDictionary(const string& filename){
  unordered_set<string>dictionary;
  ifstream file(filename);
  if (!file){
    cout << "Error, could not open file "<< filename << endl;
    exit(1);
  }
  string word;
  while (file >> word)
  {
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    dictionary.insert(word);
  }
  file.close();
  return dictionary;
  
}
//function to initialize the Game board and display board
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
// function to check volid and winner
bool isValidword(const unordered_set<string>& dictionary, const string& word){
  return dictionary.find(word) != dictionary.end();
}
bool CheckWinner(const vector<vector<char>>& Board, const unordered_set<string>& dictionary){
  vector<string> lines;
  for (int j = 0; j < SIZE; ++j){
    string col;
    for (int i = 0; i < SIZE; ++i){
      col += Board[i][j];
    }
    lines.push_back(col);
  }
  string diag1, diag2;
  for (int i = 0; i < SIZE; ++i){
    diag1 += Board[i][i];
    diag2 += Board[i][SIZE - i - 1];
  }
  lines.push_back(diag1);
  lines.push_back(diag2);
  for (const auto& line : lines){
    if (line.size() == 3 && isValidword(dictionary, line)){
       return true;
    }
  }
  return false;
}
// the main function 
int main(){
  //LOAD THE DICTIONARY AND INITIALIZE THE BOAD
  unordered_set<string> dictionary = loadDictionary("dic.txt");

  vector <vector<char>> Board;
  initializeBoard(Board);

  int turn = 0;
  int moves = 0;
  cout << "Welcome to the word TIC_TAC_TOE!"<< endl;
  cout << "Players take turns placing letters to the for valid 3-letter word." << endl;

  while (true){
    displayBoard(Board);
    char letter;
    int row, col;
    cout << "player "<<(turn + 1)<<", Enter your move: ";
    cin >> letter >> row >> col;
   
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE ||Board[row][col] != ' '){
      cout << "invalid move, try again.\n";
      continue;
    }
    letter = toupper(letter);
    Board[row][col] = letter;
    ++moves;

    if (CheckWinner(Board, dictionary)){
      displayBoard(Board);
      cout << "player "<< (turn + 1) << "Wins by forming a volid word"<< endl;
      break;
    }
    if (moves == SIZE * SIZE){
      displayBoard(Board);
      cout <<" It is a draw, not volid words formed."<< endl;
      break;
    }
    turn = 1- turn;
  }
  return 0;
}