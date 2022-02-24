//Console Tic-Tac-Toe
//Computer plays against user
//Practice exercise from Beginning C++ Through Game Programming by Michael Dawson

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//global char variables
const char X='X';
const char O='O';
const char EMPTY=' ';
const char TIE='T';
const char NO_ONE='N';

//function prototypes
void showRules();
void showBoard(const vector<char>& board);
char askTurn(string question);
int askStep(string question, int high,int low=0);
char getHumanPiece();
char getOpponentPiece(char piece);
char getWinner(const vector<char>& board);
bool isLegalMove(const vector<char>& board, int move);
int getHumanMove(const vector<char>& board, char humanPiece);
int getComputerMove(const verctor<char>& board, char computerPiece);
void announceWinner(char winner, char computerPiece, char humanPiece);

int main(){
  int move;
  const int N_SQUARES=9;
  vector<char> board(N_SQUARES,EMPTY);

  showRules();
  char humanPiece=getHumanPiece();
  char computerPiece=getOpponentPiece(human);
  char turnNow='X';

  showBoard(board);
  while(getWinner(board)==NO_ONE){
    if (turnNow==humanPiece){
      move=getHumanMove(board,humanPiece);
      board[move-1]=humanPiece;
    }
    else{
      move=getComputerMove(board,computerPiece);
      board[move-1]=computer;
    }
  }
  announceWinner(getWinne(board),computerPiece,humanPiece);
  return 0;
}
