#include<iostream>
#include<string>
#include<algorithm>
#define BUF 1005
#define INF (1<<20)
using namespace std;

int nUniv, nQuery;
string univ[BUF], query[BUF];

void read(){
  string dummy;

  cin >> nUniv;
  getline(cin,dummy);
  for(int i=0;i<nUniv;i++) getline(cin,univ[i]);

  cin >> nQuery;
  getline(cin,dummy);
  for(int i=0;i<nQuery;i++) getline(cin,query[i]);
}

void work(int cases){
  static int dp[BUF][BUF];  //[univId][queryId]
  for(int i=0;i<nUniv;i++)
    for(int j=0;j<nQuery;j++)
      dp[i][j] = INF;

  for(int i=0;i<nUniv;i++)
    if(query[0]!=univ[i])
      dp[i][0] = 0;

  for(int i=0;i+1<nQuery;i++)
    for(int cur=0;cur<nUniv;cur++)
      for(int nex=0;nex<nUniv;nex++){
        if(query[i+1]==univ[nex]) continue;
        
        if(cur!=nex)
          dp[nex][i+1] = min(dp[nex][i+1],dp[cur][i]+1);
        else
          dp[nex][i+1] = min(dp[nex][i+1],dp[cur][i]);
      }

  int minV = INF;
  for(int i=0;i<nUniv;i++)
    minV = min(minV,dp[i][nQuery-1]);

  cout << "Case #" << cases << ": " << minV << endl;
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
