#include <stdio.h>
#include <curses.h>

int check_victory(char board[4][4], char candidate) {
 int line, column;
 for(line=0;line<4;line++) {
  if(((board[line][0]==candidate)||(board[line][0]=='T'))&&((board[line][1]==candidate)||(board[line][1]=='T'))&&
    ((board[line][2]==candidate)||(board[line][2]=='T'))&&((board[line][3]==candidate)||(board[line][3]=='T'))) {
   return(1);
  }
 }
 for(column=0;column<4;column++) {
  if(((board[0][column]==candidate)||(board[0][column]=='T'))&&((board[1][column]==candidate)||(board[1][column]=='T'))&&
    ((board[2][column]==candidate)||(board[2][column]=='T'))&&((board[3][column]==candidate)||(board[3][column]=='T'))) {
   return(1);
  }
 }
  if(((board[0][0]==candidate)||(board[0][0]=='T'))&&((board[1][1]==candidate)||(board[1][1]=='T'))&&
    ((board[2][2]==candidate)||(board[2][2]=='T'))&&((board[3][3]==candidate)||(board[3][3]=='T'))) {
   return(1);
  }
  if(((board[0][3]==candidate)||(board[0][3]=='T'))&&((board[1][2]==candidate)||(board[1][2]=='T'))&&
    ((board[2][1]==candidate)||(board[2][1]=='T'))&&((board[3][0]==candidate)||(board[3][0]=='T'))) {
   return(1);
  }
 return(0);
}

int check_dot(char board[4][4]) {
 int line, column;
 for(line=0;line<4;line++) {
  for(column=0;column<4;column++)
   if(board[line][column]=='.') return(1);
 }
 return(0);
}

void print_board(char board[4][4]) {
 int line, column;
 for(line=0;line<4;line++)
  printf("%c%c%c%c\n", board[line][0], board[line][1], board[line][2], board[line][3]);
// for(column=0;column<4;column++) {
//  printf("line %d column %d: %c\n", line, column, board[line][column]);
// }
 return;
}

int main(void){
 int cases, i, j, k;
 char board[4][4], tempchar;
 scanf("%d", &cases);
// printf("%d cases\n", cases);
 for(i=0;i<cases;i++) {
  for(j=0;j<4;j++) for(k=0;k<4;k++) board[j][k]='-';
  for(j=0;j<4;j++) {
    scanf("%c", &tempchar);
    scanf("%c%c%c%c", &(board[j][0]), &(board[j][1]), &(board[j][2]), &(board[j][3]));
//    board[j][k] = (char) getch();
//   }
//   scanf("%c\n", &(board[j][3]));
  }
  scanf("%c", &tempchar);
//  print_board(board);
  if(check_victory(board, 'X')) printf("Case #%d: X won\n", i+1);
  else if(check_victory(board, 'O')) printf("Case #%d: O won\n", i+1);
  else if(check_dot(board)) printf("Case #%d: Game has not completed\n", i+1);
  else printf("Case #%d: Draw\n", i+1);
 }
 return(0);
}
