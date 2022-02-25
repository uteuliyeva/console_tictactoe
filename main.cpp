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
int askMove(string question, int high,int low=1);
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
  char computerPiece=getOpponentPiece(humanPiece);
  char turnNow=X;

  showBoard(board);
  while(getWinner(board)==NO_ONE){
    if (turnNow==humanPiece){
      move=getHumanMove(board,humanPiece);
      board[move]=humanPiece;
    }
    else{
      move=getComputerMove(board,computerPiece);
      board[move]=computerPiece;
    }
    showBoard(board);
    turnNow=getOpponentPiece(turnNow);
  }
  announceWinner(getWinner(board),computerPiece,humanPiece);
  return 0;
}

void showRules(){
  cout<<"---TIC-TAC-TOE---\n\n";
  cout<<"Here you can make moves by choosing a number 1-9.\n";
  cout<<"Each number corresponds to the position on the board"\n";
  cout<<"\t 1 | 2 | 3 "<<endl;
  cout<<"\t ----------"<<endl;
  cout<<"\t 4 | 5 | 6 "<<endl;
  cout<<"\t ----------"<<endl;
  cout<<"\t 7 | 8 | 9 "<<endl;
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

char getOpponentPiece(char piece){
  if (piece==X){
    return O;
  }
  else{
    return X;
  }
}

void showBoard(const vector<char>& board){
  cout<<"\t "<<board[0]<<" | "<<board[1]" | "<<board[2]<<" "<<endl;
  cout<<"\t ----------"<<endl;
  cout<<"\t "<<board[3]<<" | "<<board[4]" | "<<board[5]<<" "<<endl;
  cout<<"\t ----------"<<endl;
  cout<<"\t "<<board[6]<<" | "<<board[7]" | "<<board[8]<<" "<<endl;
  cout<<"\n\n";
}

char getWinner(const vector<char>& board){
  //all possible winning rows
  const int WINNING_ROWS[8][3]={{0,1,2},{3,4,5},{6,7,8},
  {0,3,6},{1,4,7},{2,5,8},
  {0,4,8},{2,4,6}}
  const int N_ROWS=8;
  //check whether one of the rows is filled with same pieces
  for (int row=0;row<N_ROWS;++row){
    if(WINNING_ROWS[row][0]!=EMPTY&&
      WINNING_ROWS[row][0]==WINNING_ROWS[row][1]&&
      WINNING_ROWS[row][1]==WINNING_ROWS[row][2]){
        return WINNING_ROWS[row][0];
      }
  }
  //check for tie
  if (count(board.begin(),board.end(),EMPTY)==0){
    return TIE;
  }
  //no one is winner yet
  return NO_ONE;
}

int getHumanMove(const vector<char>& board, char humanPiece){
  string question="Enter your next move (1-9).";
  int move=askMove(question,board.size());
  while(!isLegalMove(board,move)){
    cout<<"That position is occupied.\n";
    move=askMove("Please choose again (1-9).",board.size());
  }
  cout<<"Ok!";
  return move-1;
}

bool isLegalMove(const vector<char>& board, int move){
  return (board[move]==EMPTY)
}
