#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int cases = 0;
  cin >> cases;
  int cas = cases;

  //vector<string> output;
  char output[1000][50];
  for(int c = 0; c < cas; c++)
    {
      char sink[1];

      char board[4][4];
      ostringstream stringStream;

      for(int i = 0; i < 4; i++)
	{ 
	  for(int j = 0; j < 4; j++)
	    board[i][j] = '.';
	  cin >> board[i];
	}

      //scanf("\n");
      cin.getline(sink, 1);
      cin.getline(sink, 1);
      

      char original;
      int k = 0;
      
      //Diagonal
      if(board[0][0] == 'T') original = board[1][1];
      else original = board[0][0];
      for(k=0; k < 4; k++)
	{
	  if(board[k][k] == 'T')continue;
	  if(board[k][k] == '.') break;
	  if(original == board[k][k] || board[k][k] == 'T')continue;
	  else break;
	}
      if(k == 4)
	{
	  stringStream << "Case #" << c+1 << ": " << original << " won\n";
	  string str = stringStream.str();
	  //output.push_back(str);
	  strcpy(output[c], str.c_str());
	  continue;
	}
      
      if(board[3][0] == 'T') original = board[2][1];
      else original = board[3][0];

      for(k=0; k < 4; k++)
	{
	  if(board[3-k][k] == 'T')continue;
	  if(board[3-k][k] == '.') break; 
	  if(original == board[3-k][k] || board[3-k][k] == 'T')continue;
	  else break;
	}
      if(k == 4)
	{
	  stringStream << "Case #" << c+1 << ": " << original << " won\n";
	  string str = stringStream.str();
	  //output.push_back(str);
	  strcpy(output[c], str.c_str());
	  continue;
	}

      int flag = 0;
      int ydot[4] = {0, 0, 0, 0};

      //Rows
      int count = 0;
      for(int i = 0; i < 4; i++)
	{
	  k = 0;
	  if(board[k][i] == 'T') k++;
	  if(board[k][i] == '.')
	    {
	      count++;
	      ydot[k] = 1;
	      continue;
	    }
	  original = board[k][i];
	  k++;
	  for(;k < 4; k++)
	    {
	      if(board[k][i] == '.')
		{
		  count++;
		  ydot[i] = 1;
		  break;
		}
	      else if(original == board[k][i] || board[k][i] == 'T') { continue; }
	      else break;
	    }

	  if(k == 4)
	    {
	      stringStream << "Case #" << c+1 << ": " << original << " won\n";
	      string str = stringStream.str();
	      //output.push_back(str);
	      strcpy(output[c], str.c_str());
	      flag = 1;
	      break;
	    }
	}
      
      if(flag) continue;
      //columns
      for(int i = 0; i < 4; i++)
	{
	  //if (ydot[i] == 1) continue;

	  k = 0;
	  if(board[i][k] == 'T') k++;
	  if(board[i][k] == '.')
	    {
	      count++;
	      continue;
	    }
	  original = board[i][k];
	  k++;
	  for(;k < 4; k++)
	    {
	      if(board[i][k] == '.')
		{
		  count++;
		  break;
		}
	      else if(original == board[i][k] || board[i][k] == 'T') { continue; }
	      else break;
	    }

	  if(k == 4)
	    {
	      stringStream << "Case #" << c+1 << ": " << original << " won\n";
	      string str = stringStream.str();
	      //output.push_back(str);
	      strcpy(output[c], str.c_str());
	      flag = 1;
	      break;
	    }
	}
      if(!flag)
	if(count > 0) 
	  {
	    stringStream << "Case #" << c+1 << ": Game has not completed\n";
	    string str = stringStream.str();
	    //output.push_back(str);
	    strcpy(output[c], str.c_str());
	  }
	else
	  {
	    stringStream << "Case #" << c+1 << ": Draw\n";
	    string str = stringStream.str();
	    try
	      {
		//output.push_back(str);
		strcpy(output[c], str.c_str());
	      }
	    catch(exception &e)
	      {
		cout << e.what() << endl;
	      }
	  } 
    }

  //for(vector<string>::iterator it = output.begin(); it != output.end(); it++)
  for(int i = 0; i < cas; i++)
    {
      cout << output[i];
    }
}
