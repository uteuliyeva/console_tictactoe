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

void showRules(){
  cout<<"---TIC-TAC-TOE---\n\n";
  cout<<"Here you can make moves by choosing a number 1-9.\n";
  cout<<"Each number corresponds to the position on the board"\n";
  cout<<"1|2|3"<<endl;
  cout<<"-----"<<endl;
  cout<<"4|5|6"<<endl;
  cout<<"-----"<<endl;
  cout<<"7|8|9"<<endl;
}

char getHumanPiece(){
  char response;
  string question="Please choose your piece. Press X or O. X goes first.";
  do{
    cout<<"\n"<<question<<"\n";
    cin>>response;
  }while(response!='x'&&response!='X'&&response!='y'&&response!='Y');
  return toupper(response);
}
