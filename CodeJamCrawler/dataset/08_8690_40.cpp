#include<iostream>
#define BUF (10)
#define INF (1<<20)
using namespace std;

int row, col;
bool seat[BUF][BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;
      seat[i][j] = ch=='.';
    }
}

int rec(int r, int pre, int dp[BUF][1<<BUF]){
  if(r==row) return 0;
  if(dp[r][pre]>=0) return dp[r][pre];
  
  int &ret = dp[r][pre];
  for(int nex=0;nex<(1<<col);nex++){
    bool ok = true;
    int cnt = 0;
    for(int i=0;i<col;i++){
      if(!(nex&(1<<i))) continue;
      cnt++;
      if(!seat[r][i]) ok = false;
      if((pre&(1<<(i+1)))) ok = false;
      if(i>0 && (pre&(1<<(i-1)))) ok = false; 
      if(i>0 && (nex&(1<<(i-1)))) ok = false; 
      if(!ok) break;
    }

    if(ok){
      ret = max(ret,rec(r+1,nex,dp)+cnt);
    }
  }
  return ret;
}

void work(int cases){
  int dp[BUF+1][1<<BUF]; //(row,1<<col)
  for(int i=0;i<=BUF;i++)
    for(int j=0;j<(1<<BUF);j++)
      dp[i][j] = -INF;
  
  cout << "Case #" << cases << ": " << rec(0,0,dp) << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
