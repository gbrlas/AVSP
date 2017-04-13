#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
  int t, kase = 1;

  char board[4][4];
  int board_values[4][4];
  int status;
  int i,j;
  int tx, ty;
  int full;
  char winner;
  scanf("%d\n",&t);

  while(t--){
    tx = -1; ty = -1;
    full = 1;
    for(i=0; i<4; i++)
      for(j=0; j<4; j++)
      {
        scanf("%c\n",&board[i][j]);
        if(board[i][j] == 'T')
        {
          tx = i;
          ty = j;
        } 
        if(board[i][j] == '.')
          full = 0;
      }

    status = 0;

    for(j=0;j<2;j++){
      if(tx > -1){
        if(j==0)
          board[tx][ty]= 'O';
        else
          board[tx][ty]= 'X';
      }
        
	    for(i=0; i<4; i++){
	      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3]){
	        if(board[i][0] != '.')
	          status = 1, winner = board[i][0];
	      }
	      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i]){
	        if(board[0][i] != '.')
	          status = 1, winner = board[0][i];
	      }
	    }
	
	    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3]){
	      if(board[0][0] != '.')
	        status = 1, winner = board[0][0];
	    }
	    if(board[3][0] == board[2][1] && board[3][0] == board[1][2] && board[3][0] == board[0][3]){
	      if(board[3][0] != '.')
	        status = 1, winner = board[3][0];
	    }
    }
    if(!status && full == 1)
      status = 3;
    else if(!status)
      status = 4;

    printf("Case #%d: ", kase++);
    switch(status){
      case 1:
        printf("%c won\n", winner);
        break;
      case 3:
        printf("Draw\n");
        break;
      case 4:
        printf("Game has not completed\n");
        break;
    }
  }
  return 0;
}

