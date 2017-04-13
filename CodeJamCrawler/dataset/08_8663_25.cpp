#include<iostream>
#define BUF 10005
using namespace std;

class Node{
public:
  bool leaf;

  // if interior
  int gate, change;

  // if leaf
  int value;
};

int nNode, dst;
Node nodes[BUF];

void read(){
  cin >> nNode >> dst;
  
  for(int i=0;i<(nNode-1)/2;i++){
    nodes[i].leaf = false;
    cin >> nodes[i].gate >> nodes[i].change;
  }

  for(int i=(nNode-1)/2;i<nNode;i++){
    nodes[i].leaf = true;
    cin >> nodes[i].value;
  }
}

int rec(int idx, int val, int dp[BUF][2]){
  if(dp[idx][val]!=(1<<20)) return dp[idx][val];
  if(nodes[idx].leaf){
    if(nodes[idx].value==val)
      dp[idx][val] = 0;
    return dp[idx][val];
  }
  
  int minV = (1<<20);
  if(nodes[idx].gate==1){

    if(val==1){
      // to one
      minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,1,dp));

      if(nodes[idx].change==1){
	minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,1,dp)+1);
	minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,0,dp)+1);
      }
    }
    else{
      // to zero
      minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,0,dp));
      minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,0,dp));
      minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,1,dp));
    }
  }
  else{
    if(val==1){
      // to one
      minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,1,dp));
      minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,0,dp));
      minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,1,dp));
    }
    else{
      // to zero
      minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,0,dp));

      if(nodes[idx].change==1){
	minV = min(minV,rec(idx*2+1,0,dp)+rec(idx*2+2,1,dp)+1);
	minV = min(minV,rec(idx*2+1,1,dp)+rec(idx*2+2,0,dp)+1);
      }      
    }
  }
  
  return dp[idx][val] = minV;
}

void work(int cases){
  int dp[BUF][2];

  for(int i=0;i<nNode;i++)
    for(int j=0;j<2;j++)
      dp[i][j] = (1<<20);

  rec(0,0,dp);
  rec(0,1,dp);

  cout << "Case #" << cases << ": ";
  if(dp[0][dst]==(1<<20))
    cout << "IMPOSSIBLE" << endl;
  else
    cout << dp[0][dst] << endl;
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
