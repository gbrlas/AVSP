#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

#define  CTRL(xx,yy,cc) (d[xx][yy]==cc || d[xx][yy]=='T')
#define  wait system("PAUSE")
#define  INF INT_MAX
#define  mkp make_pair
#define  pb push_back
#define  f first

using namespace std;

int N=4;
char d[15][15];

void oku(){
  int i,j;
  for(i=1; i<=N; i++)
    for(j=1; j<=N; j++)
      scanf(" %c",&d[i][j]);
}

bool ctrl(char c,int s,int yer){
  int i=1,j=1,x=1,y=N;
  while(i<=N && ((s==1 && (d[yer][i]==c || d[yer][i]=='T')) ||
                 (s==2 && (d[i][yer]==c || d[i][yer]=='T')) ||
                 (s==3 && (d[i][j]==c || d[i][j]=='T')) ||
                 (s==4 && (d[x][y]==c || d[x][y]=='T')))) i++,j++,x++,y--;
  return i==N+1;
}

string coz(){
  int i,j;
  for(i=1; i<=N; i++){
    if(CTRL(i,1,'X') && ctrl(d[i][1],1,i)) return "X won";
    if(CTRL(1,i,'X') && ctrl(d[1][i],2,i)) return "X won";
    if(CTRL(i,1,'O') && ctrl(d[i][1],1,i)) return "O won";
    if(CTRL(1,i,'O') && ctrl(d[1][i],2,i)) return "O won";
  }
  if(CTRL(1,1,'X') && ctrl(d[1][1],3,i)) return "X won";
  if(CTRL(1,N,'X') && ctrl(d[1][N],4,i)) return "X won";

  if(CTRL(1,1,'O') && ctrl(d[1][1],3,i)) return "O won";
  if(CTRL(1,N,'O') && ctrl(d[1][N],4,i)) return "O won";

  for(i=1; i<=N; i++)
    for(j=1; j<=N; j++)
      if(d[i][j]=='.')
        return "Game has not completed";
  return "Draw";
}

int main(){
  int t,Test_Case;
  scanf("%d",&Test_Case);
  for(t=1; t<=Test_Case; t++){
    oku();
    printf("Case #%d: %s\n",t,coz().c_str());
  }
  return 0;
}
