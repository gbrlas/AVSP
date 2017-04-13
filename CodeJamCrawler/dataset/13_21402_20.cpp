// Written by Robert L Szkutak II
// r0szsoft@gmail.com

#include <iostream>
#include <fstream>
#include <cstdlib>

#define X 1
#define O 2
#define T 3
#define E 0 // EMPTY

using namespace std;

class Board
{
      public:
          Board();
          ~Board();
          void populateRow(int row, string pop);
          string getState();
      private:
          int board[4][4];
          bool equ(int r1, int c1, int r2, int c2);
};

Board::Board()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = E;
}

Board::~Board()
{
}

bool Board::equ(int r1, int c1, int r2, int c2)
{
     if(board[r1][c1] == board[r2][c2])
         return true;
     else if(board[r1][c1] == T || board[r2][c2] == T)
         return true;
     return false;
}

string Board::getState()
{          
       //Check for diagonal win
       if(equ(0,0,1,1) && equ(1,1,2,2) && equ(2,2,3,3) && equ(0,0,3,3) && board[0][0] != E)
           if(board[0][0] == X || board[1][1] == X)
               return "X won";
           else
               return "O won";
       
       if(equ(0,3,1,2) && equ(1,2,2,1) && equ(2,1,3,0) && equ(0,3,3,0) && board[0][3] != E)
           if(board[0][3] == X || board[1][2] == X)
               return "X won";
           else
               return "O won";
           
       //Check for horizontal win
       for(int i = 0; i < 4; i++)
           for(int j = 1; j < 4; j++)
           {
               if((board[i][j] != board[i][j-1] && board[i][j] != T && board[i][j-1] != T) || board[i][j] == E || board[i][j-1] == E)
                   break;
               else
                   if(j == 3 && equ(i,0,i,3))
                   {
                        if(board[i][j] == X || board[i][j-1] == X)
                            return "X won";
                        else
                            return "O won";
                   }
           }
       
       //Check for vertical win
       for(int i = 0; i < 4; i++)
           for(int j = 1; j < 4; j++)
           {
               if((board[j][i] != board[j-1][i] && board[j][i] != T && board[j-1][i] != T) || board[j][i] == E || board[j-1][i] == E)
                   break;
               else
                   if(j == 3 && equ(0,i,3,i))
                   {
                        if(board[j][i] == X || board[j-1][i] == X)
                            return "X won";
                        else
                            return "O won";
                   }
           }
       
       //Check for not completed
       for(int i = 0; i < 4; i++)
           for(int j = 0; j < 4; j++)
           {
               if(board[i][j] == E)
                   return "Game has not completed";
           }
           
       return "Draw";
}

void Board::populateRow(int row, string pop)
{
     for(int i = 0; i < 4; i++)
     {
         string s(pop.substr(i, 1));
         if(s.compare(string("T")) == 0)
             board[row][i] = T;
         if(s.compare(string("X")) == 0)
             board[row][i] = X;
         if(s.compare(string("O")) == 0)
             board[row][i] = O;
         if(s.compare(string(".")) == 0)
             board[row][i] = E;
     }
}

int main()
{
    string output;
    Board board;
    
    //Read in a file line by line
    string line;
    int cases = 0;
    ifstream myfile ("A-small-attempt3.in");
    if (myfile.is_open())
    {
     if ( myfile.good() )
     {
       getline (myfile,line);
       cases = atoi(line.c_str());
       int counter = 0, scounter = 0;
       while(myfile.good() && counter < cases*4)
       {
              getline(myfile, line);
              board.populateRow(scounter, line);
              scounter++;
              if(scounter > 3)
              {
                  char buff[55];
                  output += "Case #" + string(itoa(counter/4+1, buff, 10)) + ": " + board.getState() + "\n";
                  scounter = 0;
                  getline(myfile, line);
              }
              counter++;
       }
     }
     myfile.close();
    }
    else cout << "Unable to open file";
    
    ofstream outfile ("output.txt");
    if (outfile.is_open())
    {
        outfile << output;
        outfile.close();
    }
    else cout << "Unable to open file";
    
    return 0;
}
