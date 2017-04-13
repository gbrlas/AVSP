#include<iostream>
#define MOD 10007
#define BUF 105
using namespace std;

int row, col;
bool wall[BUF][BUF];

void read(){
  int nWall;
  cin >> row >> col >> nWall;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      wall[i][j] = false;

  for(int i=0;i<nWall;i++){
    int r, c;
    cin >> r >> c;
    wall[r-1][c-1] = true;
  }
}

void work(int cases){
  int dp[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      dp[i][j] = 0;
  dp[0][0] = 1;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(i+1<row && j+2<col && !wall[i+1][j+2])
        dp[i+1][j+2] = (dp[i+1][j+2]+dp[i][j])%MOD;

      if(i+2<row && j+1<col && !wall[i+2][j+1])
        dp[i+2][j+1] += (dp[i+2][j+1]+dp[i][j])%MOD;
    }

  cout << "Case #" << cases << ": " << dp[row-1][col-1] << endl;
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
